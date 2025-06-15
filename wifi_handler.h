
#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <WiFi.h>
#include <Preferences.h>
#include <WebServer.h>

Preferences preferences;
WebServer server(80);

String ssid = "";
String password = "";

void saveCredentials(const String& ssid, const String& pass) {
  preferences.begin("wifi", false);
  preferences.putString("ssid", ssid);
  preferences.putString("password", pass);
  preferences.end();
}

void loadCredentials() {
  preferences.begin("wifi", true);
  ssid = preferences.getString("ssid", "");
  password = preferences.getString("password", "");
  preferences.end();
}

void handleRoot() {
  String page = "<html><body><h2>WiFi Configuration</h2><form action='/save'>";
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; i++) {
    page += "<input type='radio' name='ssid' value='" + WiFi.SSID(i) + "'>" + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + " dBm)<br>";
  }
  page += "<br>Password: <input type='password' name='pass'><br><input type='submit' value='Save & Reboot'></form></body></html>";
  server.send(200, "text/html", page);
}

void handleSave() {
  String newSSID = server.arg("ssid");
  String newPass = server.arg("pass");
  saveCredentials(newSSID, newPass);
  server.send(200, "text/html", "<html><body><h2>Saved. Rebooting...</h2></body></html>");
  delay(2000);
  ESP.restart();
}

void handleStatus() {
  String json = "{";
  json += "\"voltage\":\"12.3V\",";
  json += "\"pwr_ok\":true,";
  json += "\"sd\":\"Mounted\",";
  json += "\"wifi\":\"" + WiFi.localIP().toString() + "\",";
  json += "\"pixels\":\"Active\",";
  json += "\"relays\":[" "1,0,1,0,0,0,0,0" ];
  json += "}";
  server.send(200, "application/json", json);
}

void handleSend() {
  if (server.hasArg("cmd")) {
    String cmd = server.arg("cmd");
    Serial.println("Received CMD: " + cmd);
    // TODO: add handleCommand(cmd) logic
    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Missing cmd");
  }
}

void startAPMode() {
  WiFi.softAP("Showduino_ESP32");
  server.on("/", handleRoot);
  server.on("/save", handleSave);
  server.on("/status", handleStatus);
  server.on("/send", handleSend);
  server.begin();
  Serial.println("[WiFi] AP Mode Started. Connect to 'Showduino_ESP32' and open 192.168.4.1");
}

void connectToWiFi() {
  // loadCredentials();     <--- COMMENT THIS OUT
  // Bypass WiFi attempt entirely
  Serial.println("[WiFi] FORCING AP MODE...");
  startAPMode();
}


/*void connectToWiFi() {
  loadCredentials();

  if (ssid.length() > 0) {
    WiFi.begin(ssid.c_str(), password.c_str());
    Serial.print("[WiFi] Connecting to ");
    Serial.print(ssid);
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 15) {
      delay(500);
      Serial.print(".");
      attempts++;
    }
    Serial.println();
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("[WiFi] Connected! IP address: " + WiFi.localIP().toString());

      server.on("/status", handleStatus);
      server.on("/send", handleSend);
      server.begin();

      return;
    }
  }

  Serial.println("[WiFi] Failed to connect. Starting AP mode...");
  startAPMode();
}
*/
void handleWiFiLoop() {
  server.handleClient();
}

#endif
