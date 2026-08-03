#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BUZZER 4

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

typedef struct {
  float distance;
  float lat;
  float lon;
  float speed;
} Message;

Message data;

void onReceive(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  memcpy(&data, incomingData, sizeof(data));

  Serial.println("----- RECEIVED -----");

  Serial.print("Distance: ");
  Serial.println(data.distance);

  Serial.print("Speed: ");
  Serial.println(data.speed);

  Serial.print("Lat: ");
  Serial.println(data.lat, 6);

  Serial.print("Lon: ");
  Serial.println(data.lon, 6);

  Serial.print("Map: https://maps.google.com/?q=");
  Serial.print(data.lat, 6);
  Serial.print(",");
  Serial.println(data.lon, 6);

  // OLED DISPLAY
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Dist: ");
  display.print(data.distance);

  display.setCursor(0, 10);
  display.print("Speed: ");
  display.print(data.speed);

  display.setCursor(0, 20);
  display.print("Lat:");
  display.print(data.lat, 4);

  display.setCursor(0, 30);
  display.print("Lon:");
  display.print(data.lon, 4);

  if ((data.distance > 0 && data.distance < 20) || data.speed > 60) {
    digitalWrite(BUZZER, HIGH);
    display.setCursor(0, 50);
    display.print("ALERT!");
  } else {
    digitalWrite(BUZZER, LOW);
  }

  display.display();

  Serial.println("---------------------");
}

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER, OUTPUT);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    return;
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("System Ready");
  display.display();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_register_recv_cb(onReceive);
}

void loop() {}