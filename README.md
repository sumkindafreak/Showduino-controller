Showduino: Immersive Show Control System

Showduino is a modular, Arduino + ESP32-based system for controlling immersive scare attractions, escape rooms, and interactive theatrical environments. It has evolved into a professional-grade, fully customizable show controller supporting lighting, audio, fog, fire, motion triggers, and scene-based automation.


---

🚦 System Architecture (Phase 4 – 2025)

Showduino is made up of three tightly integrated modules:

🖥️ 1. ESP32 Touchscreen Interface (CYD Panel)

2.8" touchscreen with pill-style UI

SD card-based icon menus

Real-time diagnostics, clock sync, and status indicators

Touchscreen + IR remote navigation

Controls and displays:

WiFi + Bluetooth status

SD card presence

NeoPixel + Relay activity

System voltage, temperature, diagnostics

Log file creation with [DATE TIME] stamps



🧠 2. ESP32 Brain (Web Controller & Scene Host)

Hosts the GoreFX Dashboard: A local offline-first PWA

Receives commands from the touchscreen and web clients

Parses .shdo scene files and dispatches FX

Provides HTTP + WebSocket API

Supports SD-based file serving, OTA updates, and serial passthrough to Mega

Acts as bridge for timeline sequences and live FX control


🔧 3. Arduino Mega (Relay, Pixel, DMX Master)

Controls:

8+ Relays (5V/12V split)

4 NeoPixel lines with segmented FX

Dual MP3 players (YX5300)

DMX effects via Conceptinetics library

SX1509 input expander (scene buttons 0–9)

RTC time sync with ESP

Diagnostics (5V, 3.3V, 12V, standby, temperature)


Command-based FX execution (e.g., FX_001:START:20:COLOR:SPEED:BRIGHT)

Modular pixel_control.h, relay_control.h, diagnostics_control.h headers



---

🧰 Key Features

🎛️ Modular Control Interface

All FX, relays, MP3s, and system commands handled via serial/WebSocket commands

Supports static + parametric commands with JSON parsing

Scene playback via .shdo files with timestamped FX blocks


🎨 Live FX Dashboard (GoreFX)

Visual editor with drag-and-drop timeline

MP3 drag support

Scene export/import (.shdo)

Live test triggers and FX sandbox

Scene library with save/delete/duplicate


🔍 Advanced Diagnostics

Power monitoring via ACS712

SD card logs per boot

Real-time sensor values and status columns

System fallback handling (e.g., no Mega detected)


📦 Offline-First App Hosting

ESP32 hosts all assets (HTML/CSS/JS) from SD

Instant connection via local AP + fallback

No cloud dependency for operation



---

🔩 Hardware Inventory (v4.0)

Component	Role

ESP32 Touch (CYD)	UI, menus, SD logging
ESP32 WROOM-32	App server, command parser
Arduino Mega	Hardware relay/pixel/MP3/DMX control
2x YX5300 MP3 Players	Audio playback via Mega serial
4x NeoPixel lines	FX props (Time Circuits, Candles, etc.)
8x Relays	Fog, fire, motion, etc.
RTC Module	Timekeeping + sync
SX1509	10x scene input buttons
SD Card Module	App & config storage
ACS712	Voltage/power monitoring



---

🔮 Future Roadmap

🔁 .shdo file editor on touchscreen

📲 Scene sync with Firebase/ScareSync

🧠 AI FX suggestions + scene generator

📡 RF/Mesh support for remote props

🔉 Live microphone response FX (jumpscares!)

🔐 Command encryption & scene locking



---

🔦 Bluetooth-Controlled Haunted Lantern

A self-contained FX add-on for Showduino, this ESP32-powered lantern delivers wireless, reactive lighting for horror sets and portable scares.

🛠️ Hardware

ESP32 (Bluetooth + WiFi)

7-pixel NeoPixel Jewel

5V or LiPo power

Optional mic module (MAX9814)

3D-printed lantern enclosure with mounting points


⚙️ Features

🔵 Ghostly Blue, 🔥 Candle Flicker, 💓 Red Pulse FX

🎚️ Adjustable brightness, flicker speed

🎤 Sound-activated flicker (jump response)

🔌 Bluetooth or UDP control

🔋 Battery-ready design for roaming actors


📈 Planned Upgrades

Scene sync with GoreFX timeline

Group FX sync with other lanterns

Motion-triggered effects (PIR)

Offline FX looping fallback



---

For support, documentation, or to join the hauntSync™ creator network, visit show-duino.com

