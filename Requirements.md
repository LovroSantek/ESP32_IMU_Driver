# Project Requirements Document

## Project Name: Wearable IMU-based Movement Classification System  
**Author:** Lovro Šantek  
**Year:** 2025  

## 1. Introduction  
This document defines the requirements for a wearable device based on the **ESP32 microcontroller**, equipped with an **IMU sensor**. The device will classify exercises such as **squats** or **push-ups** using an **AI model running locally** on the microcontroller. The AI model will be developed and trained from scratch.  

## 2. System Overview  
The system consists of the following key components:  

- **ESP32 Microcontroller** – Handles data acquisition, AI inference, and communication.  
- **ICM-20948 IMU Sensor** – Captures motion data (acceleration).  
- **AI Model** – Developed and trained to recognize specific movements.  
- **Battery Power** – Enables portable operation.  

## 3. Functional Requirements  

### 3.1 IMU Sensor Integration  
- The system includes an **ICM-20948 IMU sensor**.  
- A **custom driver** must be implemented to interface the sensor with the ESP32.  
- The sensor data must be **sampled at an appropriate rate** for accurate motion classification.  

### 3.2 AI Model Development and Deployment  
- **Minimum requirement:** Model must recognize **squats**.  
- The AI model will be developed using **Edge Impulse**.  
- The model must run **locally on the ESP32** without requiring cloud-based inference.  
- The model must achieve **at least 90% classification accuracy** for targeted exercises.  
- The dataset will be **collected manually** if no suitable public dataset is available.  

### 3.3 Power Management  
- The device must be **powered by a battery**.  

### 3.4 Data Visualization  
At least one of the following visualization methods must be implemented:  

1. **On-Device Display** – Small **OLED/LCD screen** showing detected exercise.  
2. **Wireless Communication (Optional)** – BLE/Wi-Fi transmission to a mobile/PC application.  

Classification must be **indicated by onboard LEDs**.  

## 4. Non-Functional Requirements  
- The **firmware must be optimized** for real-time processing.  
- The system should provide **real-time classification results** with minimal latency.  

## 5. Open Questions  
- **Preferred method for data visualization.**  
- **Dataset** – Manually collected or scraped from the internet.  
- **Additional movements** to be classified.  
