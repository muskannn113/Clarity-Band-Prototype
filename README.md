# Clarity Band: AI-Driven Closed-Loop Stress Management System

![Project Status](https://img.shields.io/badge/Status-In%20Development-orange)
![Platform](https://img.shields.io/badge/Platform-ESP32--S3--T7-blue)
![AI](https://img.shields.io/badge/AI-TinyML%20%2F%20Edge%20Impulse-green)

**Clarity Band** is a wearable biofeedback device designed to autonomously predict, monitor, and mitigate physiological stress. It features a **closed-loop system** that detects stress in real-time and immediately triggers soothing haptic vibration patterns to calm the user's nervous system.

---

## 📖 Table of Contents
- [Overview](#overview)
- [Core Innovation: Context-Aware AI](#core-innovation-context-aware-ai)
- [Hardware Architecture](#hardware-architecture)
- [Haptics & Nervous System Regulation](#haptics--nervous-system-regulation)
- [Pin Configuration](#pin-configuration)
- [Assembly & Soldering](#assembly--soldering)

---

## 🔍 Overview
Standard wearables only *track* stress. The Clarity Band **intervenes**.

By combining **Galvanic Skin Response (GSR)**, **Heart Rate (HR)**, and **Motion Data (IMU)**, the device identifies high-stress events. Once detected, it activates the **DA7280 Haptic Driver** to deliver scientifically designed vibration frequencies that stimulate the parasympathetic nervous system, grounding the user and reducing physiological arousal without requiring active user effort.

---

## 💡 Core Innovation: Context-Aware AI
The critical flaw in many stress wearables is the **"Post-Exercise False Positive."**
* *Scenario:* You finish a run and sit down. Your Heart Rate is high (120 BPM), but your Motion is zero.
* *Dumb Logic:* `High HR` + `No Motion` = `Panic Attack` -> **FALSE ALERT.**

**How it works:**
1.  **Input:** The model receives a sequence of data.
2.  **Inference:** It recognizes that the *cause* of the current High HR was previous physical activity.
3.  **Result:** It suppresses the alert during the "cool down" phase, ensuring haptics only trigger for genuine psychological stress.

---

## 🛠 Hardware Architecture

The system is built on the powerful **ESP32-S3**, utilizing its vector processing capabilities for on-device AI.

### Component List
| Component | Model | Purpose |
| :--- | :--- | :--- |
| **Microcontroller** | **LILYGO® T7 S3 ESP32-S3** | The central processing unit (Dual-core, WiFi/BT 5.0, 8MB PSRAM) running the AI model. |
| **GSR Sensor** | **Seeed Studio Grove GSR** | Measures skin conductivity (sweat gland activity). Crucial for detecting "emotional sweat" vs "thermal sweat". |
| **Biometric Sensor** | **SparkFun SEN-15219** | Pulse Oximeter & Heart Rate (MAX30101 & MAX32664) for high-fidelity HRV data. |
| **IMU (Motion)** | **MPU-6050** | 3-Axis Accelerometer & Gyro. Provides the "Activity History" context for the AI. |
| **Haptics** | **SmartElex DA7280** | **Linear Resonant Actuator (LRA) Driver**. Delivers complex, crisp vibration waveforms for nervous system regulation. |

---

## 🌊 Haptics & Nervous System Regulation
Unlike basic buzzers that just "notify" you, the **SmartElex DA7280** drives an LRA (Linear Resonant Actuator) to create precise, high-definition vibration textures.

**Therapeutic Vibration Patterns:**
We utilize specific frequencies (typically low-frequency, rhythmic pulsing) known to stimulate the **Vagus Nerve** and induce a "Rest and Digest" state.
* **Entrainment:** Rhythmic pulses that mimic a slow, resting heartbeat (~60 BPM), subconsciously encouraging the user's heart rate to sync with the device.
* **Grounding:** "Heavy" vibration pulses that shift focus from mental spiraling to physical sensation.
* **Waveforms:** Smooth, sinusoidal vibrations (ramp-up/ramp-down) rather than harsh on/off buzzing.

---

## ⚡ Assembly & Soldering

Reliable bio-data requires rock-solid physical connections.

1.  **Soldering Male Headers:**
    * The **LILYGO T7**, **MPU-6050**, and **SparkFun** modules shipped without pre-soldered pins.
    * **Crucial Step:** Solder **Male Header Pins** to these boards.
    * *Why?* A loose "plug-and-play" jumper wire connection will result in false stress readings.
2.  **Required Tools:**
    * Soldering Iron (Temperature adjustable).
    * Lead-free Solder Wire & Flux.
    * Safety Glasses.

---

## 🚀 Future Roadmap
- [ ] Develop custom vibration waveforms (Heartbeat, Ocean Wave, Purr).
- [ ] Collect multi-modal dataset (Rest vs. Stress vs. Activity vs. Recovery).
- [ ] Train Edge Impulse Model.
- [ ] 3D print wrist enclosure.
