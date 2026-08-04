# V2V_communication

# Vehicle-to-Vehicle (V2V) Communication Protocol and collision avoiding system

## Overview
Road accidents are often caused by delayed driver reactions, poor visibility, or lack of awareness of nearby vehicles. Traditional safety systems like airbags and ABS only reduce the impact **after** a collision occurs. the project is microcontroller-based V2V communication system with ZigBee transceivers, implementing a Time-to-Collision algorithm and autonomous braking for low-latency, safety-critical accident prevention in intelligent transportation.

This project implements a **low-cost Vehicle-to-Vehicle (V2V) communication system** using ESP32 microcontrollers, ultrasonic sensors, and GPS modules. Vehicles exchange real-time data (distance, speed, location) via the **ESP-NOW protocol** to predict and prevent collisions.  

The system provides **visual alerts (OLED display)** and **audio warnings (buzzer)** when a potential collision is detected, making driving safer in highways, fog, blind turns, and urban traffic.


## ⚙️ Technologies Used
- **ESP32** microcontrollers (Transmitter & Receiver nodes)
- **ESP-NOW protocol** for peer-to-peer wireless communication
- **Ultrasonic Sensor (HC-SR04)** for obstacle distance measurement
- **GPS Module** for location and speed tracking
- **OLED Display (SSD1306, I2C)** for real-time data visualization
- **Buzzer** for audio collision alerts
- **Arduino IDE** for programming and debugging

## System Architecture
- **Transmitter Node**
  - Collects distance (Ultrasonic) and GPS data
  - Packages into a structured message
  - Sends data every second via ESP-NOW

- **Receiver Node**
  - Receives data using callback function
  - Displays distance, speed, and location on OLED
  - Activates buzzer if:
    - Distance < 20 cm  
    - OR Speed > 60 km/h

## How to Run the Project

### 1. Hardware Setup
- Connect **Ultrasonic Sensor** to ESP32:
  - TRIG → GPIO 5  
  - ECHO → GPIO 18  
- Connect **GPS Module**:
  - TX → GPIO 16  
  - RX → GPIO 17  
- Connect **OLED Display** (Receiver side):
  - SDA → GPIO 21  
  - SCL → GPIO 22  
- Connect **Buzzer**:
  - Positive → GPIO 4  
  - Negative → GND  

### 2. Software Setup
- Install **Arduino IDE** (latest version).
- Add **ESP32 board support** via Board Manager.
- Install required libraries:
  - `esp_now.h`
  - `WiFi.h`
  - `TinyGPS++`
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`

### 3. Upload Code
- Flash **Transmitter code** to one ESP32.
- Flash **Receiver code** to another ESP32.
- Ensure the **receiver MAC address** is correctly set in the transmitter code.

### 4. Run the System
- Power both ESP32 boards.
- Transmitter continuously sends distance + GPS data.
- Receiver displays values and triggers alerts when unsafe conditions are detected.

---

## Results
- Real-time data exchange between vehicles with **low latency**.
- Accurate short-range distance measurement using ultrasonic sensor.
- Effective collision alerts via **OLED + buzzer**.
- Prototype demonstrates feasibility of **low-cost V2V safety systems**.

---

## Future Scope
- Integration with **5G** for long-range communication.
- AI-based predictive collision detection.
- Expansion to **multi-vehicle networks** for smart transportation.

---

## License
T# 🚗 Vehicle-to-Vehicle (V2V) Communication System

## 📌 Overview
Road accidents are often caused by delayed driver reactions, poor visibility, or lack of awareness of nearby vehicles. Traditional safety systems like airbags and ABS only reduce the impact **after** a collision occurs.  

This project implements a **low-cost Vehicle-to-Vehicle (V2V) communication system** using ESP32 microcontrollers, ultrasonic sensors, and GPS modules. Vehicles exchange real-time data (distance, speed, location) via the **ESP-NOW protocol** to predict and prevent collisions.  

The system provides **visual alerts (OLED display)** and **audio warnings (buzzer)** when a potential collision is detected, making driving safer in highways, fog, blind turns, and urban traffic.

---

## ⚙️ Technologies Used
- **ESP32** microcontrollers (Transmitter & Receiver nodes)
- **ESP-NOW protocol** for peer-to-peer wireless communication
- **Ultrasonic Sensor (HC-SR04)** for obstacle distance measurement
- **GPS Module** for location and speed tracking
- **OLED Display (SSD1306, I2C)** for real-time data visualization
- **Buzzer** for audio collision alerts
- **Arduino IDE** for programming and debugging

---

## 🛠️ System Architecture
- **Transmitter Node**
  - Collects distance (Ultrasonic) and GPS data
  - Packages into a structured message
  - Sends data every second via ESP-NOW

- **Receiver Node**
  - Receives data using callback function
  - Displays distance, speed, and location on OLED
  - Activates buzzer if:
    - Distance < 20 cm  
    - OR Speed > 60 km/h

---

## 🚀 How to Run the Project

### 1. Hardware Setup
- Connect **Ultrasonic Sensor** to ESP32:
  - TRIG → GPIO 5  
  - ECHO → GPIO 18  
- Connect **GPS Module**:
  - TX → GPIO 16  
  - RX → GPIO 17  
- Connect **OLED Display** (Receiver side):
  - SDA → GPIO 21  
  - SCL → GPIO 22  
- Connect **Buzzer**:
  - Positive → GPIO 4  
  - Negative → GND  

### 2. Software Setup
- Install **Arduino IDE** (latest version).
- Add **ESP32 board support** via Board Manager.
- Install required libraries:
  - `esp_now.h`
  - `WiFi.h`
  - `TinyGPS++`
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`

### 3. Upload Code
- Flash **Transmitter code** to one ESP32.
- Flash **Receiver code** to another ESP32.
- Ensure the **receiver MAC address** is correctly set in the transmitter code.

### 4. Run the System
- Power both ESP32 boards.
- Transmitter continuously sends distance + GPS data.
- Receiver displays values and triggers alerts when unsafe conditions are detected.

---

## 📊 Results
- Real-time data exchange between vehicles with **low latency**.
- Accurate short-range distance measurement using ultrasonic sensor.
- Effective collision alerts via **OLED + buzzer**.
- Prototype demonstrates feasibility of **low-cost V2V safety systems**.

---

## 🔮 Future Scope
- Integration with **5G** for long-range communication.
- AI-based predictive collision detection.
- Expansion to **multi-vehicle networks** for smart transportation.

---

## 📜 License
This project is licensed under the **Creative Commons (CC BY 4.0)** License.  
You are free to share and adapt the material, provided appropriate credit is given.  
