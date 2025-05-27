#ifndef COMMAND_MAP_H
#define COMMAND_MAP_H

#include "Arduino.h"

// These must be declared at the top level, NOT inside the function
extern HardwareSerial &pc;
extern HardwareSerial &megaSerial;
void logToSD(const String& message);
void drawRightStatusColumn(String payload);  // For SYS: handling

void handleSerialCommand(String cmd) {
  cmd.trim();
  pc.println(">> Received: " + cmd);
  logToSD(">> Received: " + cmd);

  // Handle SYS: lines here first (they don't go to the Mega)
  if (cmd.startsWith("SYS:")) {
    String payload = cmd.substring(4);  // Remove "SYS:"
    drawRightStatusColumn(payload);
    return;
  }

  // All known command prefixes (forwarded to Mega)
  const char* knownPrefixes[] = {
    "RELAY", "PULSE_RELAY",
    "PLAY_MP3_A:", "STOP_MP3_A", "PAUSE_MP3_A", "RESUME_MP3_A",
    "NEXT_MP3_A", "PREV_MP3_A", "SET_MP3_VOL:",
    "PLAY_MP3_B:", "STOP_MP3_B", "PAUSE_MP3_B", "RESUME_MP3_B",
    "NEXT_MP3_B", "PREV_MP3_B", "SET_MP3B_VOL:",
    "PIXELS_LINE", "PIXELS_ALL",
    "START_SHOW", "STOP_SHOW", "TRIGGER_",
    "PING", "VOLTAGE_CHECK", "PWR_OK_STATUS",
    "SET_BRIGHTNESS:", "SET_VOLUME:", "SET_MP3B_VOL:",
    "DMX_", "FX_", "SAVE_", "LOAD_", "CONNECT_", "LOCK_",
    "UNLOCK_", "WIFI_", "SD_", "SCENE_", "PROP_", "DIAG_",
    "CONFIG_", "TIMELINE_", "AUTH_", "SET_", "CLEAR_",
    "SHOW_", "NEO_", "VOL_", "BRIGHT_", "DEBUG_"
  };

  // Check prefix match
  bool matched = false;
  for (int i = 0; i < sizeof(knownPrefixes) / sizeof(knownPrefixes[0]); i++) {
    if (cmd.startsWith(knownPrefixes[i])) {
      matched = true;
      break;
    }
  }

  if (matched) {
    pc.println("[LOG] Forwarding to Mega: " + cmd);
    logToSD("[LOG] Forwarding to Mega: " + cmd);
    megaSerial.println(cmd);
  } else {
    pc.println("[WARN] Unknown or unsupported command: " + cmd);
    logToSD("[WARN] Unknown or unsupported command: " + cmd);
  }
}

#endif
