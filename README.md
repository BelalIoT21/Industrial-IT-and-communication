# Industrial IT and Communication

This repository contains code and resources related to industrial IT and communication projects.

## Key Features & Benefits

This repository includes:

*   MQTT communication examples using the `paho-mqtt` library in Python.
*   Code for a server that receives files over a socket connection.
*   Examples of communication between a VM server and an MQTT broker.
*   Diagrams illustrating the system architecture.

## Prerequisites & Dependencies

To run the code in this repository, you'll need the following:

*   **Python:** Version 3.6 or higher.
*   **paho-mqtt:** A Python MQTT client library. Install with `pip install paho-mqtt`.
*   **socket:** (Built-in to Python) For socket communication.
*   Arduino IDE (if using the `sketch/sketch.ino` file)
*   Wokwi Simulator (for visualizing the project)

## Installation & Setup Instructions

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/BelalIoT21/Industrial-IT-and-communication.git
    cd Industrial-IT-and-communication
    ```

2.  **Install Dependencies (if needed):**

    ```bash
    pip install paho-mqtt
    ```

3. **Navigate to the Task directory of interest (Task 1 or Task 2).**

4. **Run the python script.** For example:
    ```bash
    cd "Examination tasks/Task 1"
    python paho1.mqtt.py
    ```
    or
    ```bash
    cd "Examination tasks/Task 2"
    python paho2.mqtt.py
    python VM_SERVER.py #In a separate terminal
    ```

## Usage Examples & API Documentation

### Task 1 - MQTT Publisher/Subscriber Example (paho1.mqtt.py)

This script demonstrates a simple MQTT publisher and subscriber. It connects to the `test.mosquitto.org` broker and publishes/subscribes to a specific topic.

```python
import paho.mqtt.client as mqtt

MQTT_SERVER = "test.mosquitto.org"
# callback functions...
```

Refer to the `paho1.mqtt.py` file for the complete code.

### Task 2 - File Transfer via Sockets (VM_SERVER.py)

This script implements a server that listens for incoming socket connections and receives files.

```python
import socket
import os

SERVER_HOST = "0.0.0.0"
SERVER_PORT = 5001
# ... socket code ...
```

Refer to the `VM_SERVER.py` file for the complete code.

### Task 2 - MQTT communication with VM Server (paho2.mqtt.py)

This script implements MQTT to comunicate between the server and the Virtual Machine.

```python
import paho.mqtt.client as mqtt
import socket

MQTT_SERVER = "test.mosquitto.org"
VM_SERVER = "192.168.0.37"
# ... socket code ...
```

Refer to the `paho2.mqtt.py` file for the complete code.

## Configuration Options

*   **MQTT Broker Address:** Modify the `MQTT_SERVER` variable in `paho1.mqtt.py` and `paho2.mqtt.py` to connect to a different MQTT broker.
*   **VM Server Address:** Modify the `VM_SERVER` variable in `paho2.mqtt.py` to connect to a different VM Server.
*   **Server Port:** Modify the `SERVER_PORT` variable in `VM_SERVER.py` to change the port the server listens on.
*   **BUFFER_SIZE**: Modify the `BUFFER_SIZE` variable in both `VM_SERVER.py` and `paho2.mqtt.py` to change the buffer size of the socket.

## Contributing Guidelines

1.  Fork the repository.
2.  Create a new branch for your feature or bug fix.
3.  Make your changes and commit them with descriptive messages.
4.  Submit a pull request.

## License Information

License not specified. All rights reserved by BelalIoT21

## Acknowledgments

*   This project utilizes the `paho-mqtt` library.
*   The `test.mosquitto.org` MQTT broker is used for demonstration purposes.
*   Wokwi Online Simulator is utilized for virtualizing the Arduino Sketch.
