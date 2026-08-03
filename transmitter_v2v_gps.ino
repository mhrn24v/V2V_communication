#include <esp_now.h>
#include <WiFi.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

// Ultrasonic
#define TRIG 5
#define ECHO 18

// GPS
TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

// Receiver MAC (your MAC)
uint8_t receiverMAC[] = {0x1C, 0xC3, 0xAB, 0xC3, 0x38, 0xE4};

// Data structure
typedef struct {
  float distance;
  float lat;
  float lon;
  float speed;
} Message;

Message data;

// Ultrasonic function
float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  if (duration == 0) return -1;

  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // GPS init
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  esp_now_add_peer(&peerInfo);
}

void loop() {
  // Read Ultrasonic
  data.distance = getDistance();

  // Non-blocking GPS read
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid()) {
    data.lat = gps.location.lat();
    data.lon = gps.location.lng();
    data.speed = gps.speed.kmph();
  } else {
    data.lat = 0;
    data.lon = 0;
    data.speed = 0;
  }

  // Send data
  esp_now_send(receiverMAC, (uint8_t *)&data, sizeof(data));

  // Debug
  Serial.print("D: "); Serial.print(data.distance);
  Serial.print(" | Lat: "); Serial.print(data.lat, 6);
  Serial.print(" | Lon: "); Serial.print(data.lon, 6);
  Serial.print(" | Speed: "); Serial.println(data.speed);

  delay(1000);
}