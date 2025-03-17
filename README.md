# esp32-touchmenu for cheap yellow display
Showduino

Showduino is a versatile, Arduino-based show control system designed for immersive horror experiences, escape rooms, and interactive installations. The system combines multiple microcontrollers to deliver dynamic lighting, audio effects, and seamless control of complex environments.

System Overview

Showduino is a multi-microcontroller system that integrates:

ESP32 Touchscreen Interface – Provides a user-friendly menu for controlling brightness, settings, and system diagnostics.

ESP32 Brain – Acts as the communication hub, managing data flow between the touchscreen interface and Arduino Mega.

Arduino Mega – Controls NeoPixels, relays, and DMX effects, executing commands sent from the ESP32 Brain.

Key Features

1. Touchscreen Interface

Dynamic touchscreen menu for intuitive control.

Dedicated Brightness Control menu with real-time adjustments.

Bluetooth control via serial commands to the ESP32 Brain.

Designed for both text-based and icon-based UI (icons load from the SD card).

2. ESP32 Brain

Acts as the primary communication hub.

Manages Bluetooth connectivity and serial communication.

Relays instructions to the Arduino Mega for hardware control.

3. Arduino Mega

Controls NeoPixel displays with group-based brightness control.

Manages relay control for triggered effects.

Executes DMX sequences and lighting cues.

4. Infrared Keyboard Support

Uses a 44-button IR remote for direct system control.

Includes quick command keys for scenes, menu navigation, and system diagnostics.

Visual feedback via NeoPixels:

Green for recognized inputs.

Red for unrecognized inputs.

5. Diagnostics System

Real-time data display via the touchscreen interface.

Displays system information such as:

Bluetooth status

WiFi connection details

NeoPixel brightness settings

Relay and input status

SD card presence

Power supply readings

Temperature sensor data

I/O check results

Manual system test mode with PASS/FAIL indicators for easy troubleshooting.

6. Future Expansion Plans

Enhanced audio support with minimal memory impact.

Expanded touchscreen animations, effects, and transitions.

WiFi remote control functionality.

OTA (Over-The-Air) updates for remote code deployment.

Puzzle integration for escape room setups.

Hardware Components

ESP32 Touchscreen Display

ESP32 WROOM-32 (Brain)

Arduino Mega

SX1509 I/O Expanders (for additional inputs)

MP3 Players (for audio effects)

NeoPixel Strips & Jewels

Relay Modules

SD Card Module

RTC Module (for time-based triggers)

ACS712 Current Sensor (for power monitoring)

Communication Flow

The Touchscreen ESP32 handles UI interactions and sends commands to the ESP32 Brain via UART.

The ESP32 Brain interprets these commands and sends relevant instructions to the Arduino Mega.

The Arduino Mega executes lighting effects, relay control, and DMX commands accordingly.
