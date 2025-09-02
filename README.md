# Industrial IT and Communication 🏭📡

A comprehensive collection of industrial communication protocols and IT solutions designed for modern manufacturing and automation systems. This repository demonstrates practical implementations of MQTT messaging, socket communication, VM-to-device connectivity, and Arduino-based industrial IoT applications.

![Industrial IoT](https://img.shields.io/badge/Industrial-IoT-blue)
![MQTT](https://img.shields.io/badge/MQTT-Protocol-green)
![Python](https://img.shields.io/badge/Python-3.6%2B-brightgreen)
![Arduino](https://img.shields.io/badge/Arduino-Compatible-orange)
![Socket](https://img.shields.io/badge/Socket-Communication-red)
[![GitHub stars](https://img.shields.io/github/stars/BelalIoT21/Industrial-IT-and-communication)](https://github.com/BelalIoT21/Industrial-IT-and-communication/stargazers)

## 🎯 Overview

Industrial IT and Communication provides real-world examples and implementations of communication protocols essential for Industry 4.0 applications. From MQTT messaging for IoT devices to socket-based file transfer systems, this repository covers the fundamental building blocks of modern industrial communication infrastructure.

## 🏗️ System Architecture

```
┌─────────────────┐    ┌──────────────────┐    ┌─────────────────────┐
│   Arduino/IoT   │───▶│   MQTT Broker    │───▶│    VM Server        │
│    Devices      │    │ (Mosquitto.org)  │    │  (File Receiver)    │
└─────────────────┘    └──────────────────┘    └─────────────────────┘
         │                        │                         │
         │                        ▼                         │
         │              ┌──────────────────┐                │
         │              │  MQTT Publisher  │                │
         │              │  & Subscriber    │                │
         │              └──────────────────┘                │
         │                                                  │
         └──────────────── Socket Connection ──────────────┘
```

## ✨ Key Features

### 📡 MQTT Communication
- **Publish/Subscribe Messaging**: Efficient message distribution patterns
- **Quality of Service (QoS)**: Reliable message delivery options
- **Topic-based Routing**: Organized message categorization
- **Connection Management**: Robust connection handling with auto-reconnect
- **Multi-client Support**: Simultaneous publisher and subscriber clients

### 🔌 Socket Communication
- **TCP Socket Server**: Reliable file transfer capabilities
- **Multi-threaded Handling**: Concurrent client connections
- **File Transfer Protocol**: Secure and efficient file transmission
- **Error Handling**: Robust error recovery and logging
- **Buffer Management**: Optimized data transfer rates

### 🖥️ VM Integration
- **Virtual Machine Connectivity**: Direct communication with VM servers
- **Cross-platform Support**: Windows, Linux, macOS compatibility
- **Network Configuration**: Flexible IP and port configuration
- **Real-time Data Exchange**: Instant message and file synchronization

### 🤖 Arduino Integration
- **IoT Device Simulation**: Virtual Arduino environment with Wokwi
- **Sensor Data Publishing**: Real-time sensor data transmission
- **Remote Control**: Device control via MQTT commands
- **Industrial Protocols**: Support for standard industrial communication

## 📋 Table of Contents

- [Architecture](#architecture)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage Examples](#usage-examples)
- [Communication Protocols](#communication-protocols)
- [Arduino Integration](#arduino-integration)
- [Deployment](#deployment)
- [Monitoring](#monitoring)
- [Contributing](#contributing)

## 🔧 Prerequisites

### Software Requirements
- **Python 3.6+**: Core programming language
- **Arduino IDE**: For Arduino sketch development
- **MQTT Broker**: Mosquitto or similar (local or cloud-based)
- **Virtual Machine**: VMware, VirtualBox, or cloud VM
- **Network Access**: Internet connection for MQTT broker communication

### Python Dependencies
```bash
# Core MQTT library
pip install paho-mqtt

# Additional useful packages
pip install asyncio-mqtt     # Async MQTT support
pip install json            # JSON data handling
pip install threading       # Multi-threading support
pip install logging         # Advanced logging
```

### Arduino Requirements
- **Arduino IDE 1.8.19+**: Latest Arduino development environment
- **ESP32/ESP8266 Libraries**: For WiFi-enabled microcontrollers
- **PubSubClient**: Arduino MQTT library
- **ArduinoJson**: JSON parsing for Arduino

### System Requirements
```bash
# Minimum system specifications
- RAM: 2GB minimum, 4GB recommended
- Storage: 500MB for project files and dependencies
- Network: Stable internet connection for MQTT broker
- OS: Windows 10+, macOS 10.14+, Ubuntu 18.04+
```

## 🚀 Installation

### 1. Repository Setup
```bash
# Clone the repository
git clone https://github.com/BelalIoT21/Industrial-IT-and-communication.git

# Navigate to project directory
cd Industrial-IT-and-communication

# Explore project structure
ls -la "Examination tasks/"
```

### 2. Python Environment Setup
```bash
# Create virtual environment (recommended)
python -m venv industrial-comm-env

# Activate virtual environment
# Windows
industrial-comm-env\Scripts\activate
# macOS/Linux
source industrial-comm-env/bin/activate

# Install required packages
pip install paho-mqtt
pip install asyncio-mqtt
pip install pyserial  # For Arduino communication
```

### 3. MQTT Broker Setup
```bash
# Option 1: Use public broker (for testing)
# No setup required - uses test.mosquitto.org

# Option 2: Install local Mosquitto broker
# Ubuntu/Debian
sudo apt update
sudo apt install mosquitto mosquitto-clients

# macOS
brew install mosquitto

# Windows
# Download from: https://mosquitto.org/download/

# Start Mosquitto broker
mosquitto -v
```

### 4. Arduino IDE Configuration
```bash
# Install Arduino IDE from https://www.arduino.cc/

# Add ESP32/ESP8266 board support:
# File -> Preferences -> Additional Board Manager URLs
# Add: https://dl.espressif.com/dl/package_esp32_index.json

# Install libraries via Library Manager:
# - PubSubClient by Nick O'Leary
# - ArduinoJson by Benoit Blanchon
# - WiFi (built-in for ESP32/ESP8266)
```
