

# 🌍 Earthquake Emergency Automation System

An **offline smart automation system** that detects earthquakes using a vibration sensor and instantly activates safety mechanisms like unlocking doors, cutting electricity, shutting gas valves, and alerting users through LED and buzzer indicators. Future plans include **mobile app integration**, **cloud logging**, and **disaster awareness APIs**.

---

## 📌 Problem Statement

During earthquakes, panic and lack of immediate response can lead to life-threatening delays. This system detects vibrations indicating seismic activity and **automatically activates** key safety measures:

* **Unlocks exits**
* **Shuts off gas supply**
* **Cuts off electricity**
* **Alerts users via buzzer and LED**
* Displays real-time **gas concentration** (MQ-2)

All actions occur **offline** to ensure functionality during internet/power disruptions.

### 🔄 Future-Proofing:

The system will integrate with a **mobile app** to show:

* Real-time status of **gas valve**, **electricity**, and **door**
* “I’m Safe” toggle on Family page
* Emergency contact section
* Earthquake info via external APIs (magnitude, spread, etc.)

---

## 🧠 Features

* ✅ Earthquake detection using vibration sensor
* ✅ Servo motor door unlock (180° open)
* ✅ Solenoid latch activates twice for redundancy
* ✅ MQ-2 Gas sensor readings on serial monitor
* ✅ Dual relay system:

  * Relay 1: Controls solenoid lock
  * Relay 2: Cuts off electricity
* ✅ LED and Buzzer alerts during tremors
* 🟢 Mobile App (Future Integration):

  * “I’m Safe” toggle, emergency contacts
  * Real-time device state monitoring
  * Offline-first, disaster-resilient design

---

## ⚙️ Hardware Used

* Arduino UNO
* Vibration Sensor (SW-420)
* MQ-2 Gas Sensor
* Servo Motor (SG90)
* Solenoid Door Lock
* 2-Channel Relay Module
* LED, Buzzer
* External Power Supply for AC Bulb
* 220V AC Bulb for simulation
* Jump wires, Breadboard

---

## 🔧 Circuit Connections

| Component        | Pin Connection |
| ---------------- | -------------- |
| Vibration Sensor | A5 (Digital)   |
| MQ-2 Gas Sensor  | A0 (Analog)    |
| LED              | Pin 13         |
| Buzzer           | Pin 12         |
| Servo Motor      | Pin 9          |
| Relay 1 (Latch)  | Pin 5          |
| Relay 2 (Bulb)   | Pin 4          |

---

## 🧩 System Architecture

```
[Vibration Sensor] ─┐
                    ├─> [Arduino UNO] ──> [Servo Motor] (Unlock Door)
[MQ-2 Gas Sensor] ──┘                     [Relay 1] ─> [Solenoid Latch]
                                          [Relay 2] ─> [Bulb OFF (Electricity)]
                                          [LED + Buzzer Alert]
```

---

## 🧪 How It Works

1. **Earthquake Detected:**
   Vibration sensor sends a HIGH signal to Arduino.

2. **Automation Triggered:**

   * Servo rotates to 180° (door opens)
   * Solenoid latch moves in and out *twice*
   * Electricity cut via second relay
   * LED and Buzzer turned ON

3. **Data Logging:**

   * MQ-2 gas levels shown in serial monitor (as %)
   * Future app to reflect device state offline

4. **Post-Quake Reset:**
   LED and buzzer stop when vibration ends.

---

## 🧠 Future Enhancements

* Mobile app (offline-first with login, location, and device state)
* Real-time earthquake data using APIs (magnitude, region)
* Cloud IoT dashboard for analytics
* Bluetooth mesh sync for family networks
* Voice assistance and haptic feedback
* Emergency battery backup

---

## 🚀 Getting Started

1. Clone the repo

   ```bash
   git clone https://github.com/yourusername/earthquake-automation-system.git
   ```
2. Upload the code using Arduino IDE
3. Power the circuit and simulate vibration (shake sensor or use test motor)

---

## 📸 Screenshots (optional)

*Flow Diagram* 
![download](https://github.com/user-attachments/assets/65947618-defc-4cee-9988-01cde5293b59)

---


## 📜 License

This project is open-source under the MIT License.

