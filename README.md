# Showduino: Immersive Show Control System

**Showduino** is a powerful, Arduino-based control system designed to manage immersive horror experiences, escape rooms, and interactive installations. By combining multiple microcontrollers, Showduino delivers seamless control of lighting, audio, and environmental effects to create unforgettable experiences.

## System Overview
Showduino integrates three core components to ensure smooth performance and precise control:

- **ESP32 Touchscreen Interface** – Provides a user-friendly menu for controlling brightness, settings, and system diagnostics.
- **ESP32 Brain** – Acts as the communication hub, managing Bluetooth connectivity and relaying data between the touchscreen interface and Arduino Mega.
- **Arduino Mega** – Handles NeoPixel lighting effects, relay triggers, and DMX control based on commands received from the ESP32 Brain.

---

## Key Features
### 1. **Touchscreen Interface**
- Interactive touchscreen menu for intuitive control.
- Dedicated **Brightness Control** menu with real-time adjustments.
- Bluetooth control via serial commands to the **ESP32 Brain**.
- Supports both text-based and icon-based UI (icons load from the SD card).

### 2. **ESP32 Brain**
- Acts as the system's communication hub.
- Manages Bluetooth connectivity for remote control.
- Relays instructions to the **Arduino Mega** for hardware control.

### 3. **Arduino Mega**
- Controls NeoPixel displays with group-based brightness adjustment.
- Manages relay triggers for dynamic effects.
- Executes DMX sequences and lighting cues for immersive experiences.

### 4. **Infrared Keyboard Support**
- Utilizes a **44-button IR remote** for direct system control.
- Includes quick access command keys for:
  - Scene selection
  - Menu navigation
  - System diagnostics
- Visual feedback via NeoPixels:
  - **Green** for recognized inputs.
  - **Red** for unrecognized inputs.

### 5. **Diagnostics System**
- Displays real-time system information directly on the touchscreen interface, including:
  - Bluetooth status
  - WiFi connection details
  - NeoPixel brightness settings
  - Relay and input status
  - SD card presence
  - Power supply readings
  - Temperature sensor data
  - I/O check results
- Manual **System Test Mode** with **PASS/FAIL** indicators for easy troubleshooting.

### 6. **Future Expansion Plans**
Showduino is designed for scalability, with several planned upgrades:
- Enhanced audio support with minimal memory impact.
- Expanded touchscreen animations, effects, and transitions.
- WiFi remote control functionality.
- OTA (Over-The-Air) updates for remote code deployment.
- Puzzle integration for escape room setups.

---

## Hardware Components
- **ESP32 Touchscreen Display** (for user interface)
- **ESP32 WROOM-32** (as the Brain)
- **Arduino Mega** (for hardware control)
- **SX1509 I/O Expanders** (for additional inputs)
- **MP3 Players** (for audio effects)
- **NeoPixel Strips & Jewels** (for dynamic lighting)
- **Relay Modules** (for triggered effects)
- **SD Card Module** (for icon storage)
- **RTC Module** (for time-based triggers)
- **ACS712 Current Sensor** (for power monitoring)

---

## Communication Flow
Showduino's control structure ensures precise data management and hardware interaction:

1. **ESP32 Touchscreen Interface** handles all UI interactions, sending serial commands to the **ESP32 Brain** via UART.
2. The **ESP32 Brain** interprets these commands and relays relevant instructions to the **Arduino Mega**.
3. The **Arduino Mega** executes lighting effects, relay control, and DMX sequences based on incoming data.

This modular system design allows for future enhancements, expanded functionality, and flexible integration into immersive experiences.



------------------------------------------
# Bluetooth-Controlled Haunted Lantern

The **Bluetooth-Controlled Haunted Lantern** is a Showduino add-on designed to deliver haunting lighting effects for your immersive horror experiences. This compact and dynamic lighting solution enhances your setups with chilling visuals and wireless control.

---

## Hardware Setup
- **Microcontroller:** ESP32 (With built-in Bluetooth)
- **NeoPixels:** 7-pixel NeoPixel Jewel for dynamic lighting effects
- **Power Supply:** Suitable for both the ESP32 and NeoPixel Jewel
- **Enclosure:** Designed to resemble a traditional lantern for added realism in haunted setups.
- **Mounting Options:** Includes attachment points for wall mounting, ceiling hanging, or portable use.

---

## Functionality
✅ **Bluetooth Control:** Utilizes the ESP32’s built-in Bluetooth for wireless control.  
✅ **Lighting Effects:** Customizable lighting effects like flickering flames, eerie glows, and pulsing patterns.  
✅ **Wireless Operation:** Commands are sent via Bluetooth for seamless control.  
✅ **Compact Design:** Designed to be portable and easy to integrate into your horror setups.  
✅ **Thematic Effects:** Pre-programmed horror-themed lighting effects, including:  
   - **Pulsing Red Glow** for simulating beating hearts or sinister warnings.  
   - **Flickering Yellow Flame** for realistic candle or lantern flickers.  
   - **Ghostly Blue Aura** for ethereal or spectral appearances.  
✅ **Dynamic Brightness Control:** Adjustable brightness to match different scare intensities.  
✅ **Sound-Activated Effects:** Optional microphone integration to trigger flickering patterns based on sudden noises or screams.  

---

## Planned Enhancements
- Advanced lighting patterns for dynamic ambiance.  
- Potential interactive triggers for deeper immersion.  
- Integration with motion sensors for automatic activation in response to movement.  
- Multi-lantern synchronization for coordinated lighting effects across multiple units.  
- Battery-powered option for increased portability in outdoor or remote locations.  

