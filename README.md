# 🧠 Clarity Band  
### AI-Driven Stress Detection & Real-Time Calming Wearable

![Project Status](https://img.shields.io/badge/Status-In%20Development-orange)
![Platform](https://img.shields.io/badge/Platform-ESP32--S3--T7-blue)
![Edge](https://img.shields.io/badge/Edge%20AI-Context--Aware%20Logic-green)

**Clarity Band** is a wearable biofeedback system designed to detect physiological stress in real time and respond immediately with calming haptic feedback.  
It operates as a **closed-loop system**, combining on-device signal processing with contextual awareness to reduce false stress alerts and provide timely intervention.

---

## 📖 Table of Contents
- [Overview](#overview)
- [Core Innovation: Context-Aware Intelligence](#core-innovation-context-aware-intelligence)
- [Hardware Architecture](#hardware-architecture)
- [Haptics & Nervous System Regulation](#haptics--nervous-system-regulation)
- [Pin Configuration](#pin-configuration)
- [Assembly & Soldering](#assembly--soldering)
- [Future Roadmap](#future-roadmap)

---

## 🔍 Overview

Most consumer wearables only **track** stress and display metrics after the fact.  
**Clarity Band actively intervenes.**

By combining **Galvanic Skin Response (GSR)**, **Heart Rate (BPM)**, and **Motion Context (IMU)**, the system identifies high-stress events and triggers a gentle, non-intrusive haptic pattern designed to help the user calm down — without requiring manual input or screen interaction.

---

## 💡 Core Innovation: Context-Aware Intelligence

A major challenge in stress detection is **false positives caused by physical activity**.

### Example Problem  
- User finishes a brisk walk  
- Heart Rate remains elevated  
- Motion suddenly drops to zero  

Naive logic may interpret this as psychological stress.

### Clarity Band’s Approach
Instead of relying on single-point thresholds, Clarity Band evaluates **context**:

1. **Input:** Continuous streams of GSR, Heart Rate, and Motion
2. **Inference:** Determines whether elevated signals are caused by physical activity or stress
3. **Decision:** Suppresses alerts during activity recovery and triggers haptics only during likely stress states

This approach significantly reduces false alerts and improves user trust.

---

## 🛠 Hardware Architecture

The system is built on the **ESP32-S3**, enabling on-device processing with low latency and reliable sensor timing.

### Component List

| Component | Model | Purpose |
|---------|------|---------|
| **Microcontroller** | **LILYGO® T7 S3 ESP32-S3** | Central processing unit (Dual-core, WiFi/Bluetooth, PSRAM) |
| **GSR Sensor** | **Seeed Studio Grove GSR** | Measures skin conductance related to sympathetic nervous system activity |
| **Biometric Sensor** | **SparkFun SEN-15219** | Heart rate & pulse oximetry (MAX30101 + MAX32664) |
| **IMU** | **MPU-6050** | Motion and activity context |
| **Haptic Driver** | **SmartElex DA7280** | Drives Linear Resonant Actuator (LRA) for precise vibration control |

---

## 🌊 Haptics & Nervous System Regulation

Unlike basic vibration motors that only notify the user, the **DA7280 LRA driver** enables smooth, high-definition vibration waveforms.

### Design Principles
- **Soft ramp-up / ramp-down** (no harsh buzzing)
- **Rhythmic, low-frequency pulses**
- Designed to be **noticeable but non-distracting**

### Intended Effect
These vibration patterns are inspired by slow breathing rhythms and grounding techniques, encouraging the user to shift attention from cognitive stress to physical sensation.

> Note: This system is designed for wellness support, not medical treatment.

---

## ⚡ Pin Configuration

| Module | ESP32-S3 Pin |
|------|-------------|
| I2C SDA | GPIO 15 |
| I2C SCL | GPIO 16 |
| Pulse Sensor RESET | GPIO 13 |
| Pulse Sensor MFIO | GPIO 14 |
| GSR Analog Output | GPIO 5 |

---

## 🔧 Assembly & Soldering

Accurate bio-signal acquisition requires stable physical connections.

### Key Steps
1. **Solder male header pins** to:
   - LILYGO T7 S3
   - MPU-6050
   - SparkFun SEN-15219
2. Avoid loose jumper-only connections for biometric sensors
3. Secure GSR electrodes firmly for consistent readings

### Required Tools
- Temperature-controlled soldering iron
- Lead-free solder and flux
- Safety glasses

---

## 🚀 Future Roadmap

- [ ] Develop additional calming haptic patterns (heartbeat, wave, pulse)
- [ ] Long-term adaptive baseline calibration
- [ ] Dataset collection for activity vs. stress classification
- [ ] Lightweight ML model for improved context recognition
- [ ] Compact wrist-worn enclosure (3D printed)
- [ ] Battery-powered standalone operation

---

## 📝 Notes

- SpO₂ is treated as a **background health indicator** and may remain stable in healthy users
- Stress detection does **not** rely on SpO₂
- The project is intended for **wellness and research prototyping**, not medical diagnosis

---

## 🏁 Conclusion

Clarity Band demonstrates how multi-modal physiological sensing and haptic feedback can be combined into a responsive, real-time stress regulation system.  
By focusing on **context awareness**, **on-device intelligence**, and **user comfort**, the project lays a strong foundation for future wearable wellness applications.

---

