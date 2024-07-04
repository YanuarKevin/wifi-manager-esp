#include <WiFiManager.h>
#define TRIGGER_RES_PIN 0
int timeout = 300;

WiFiManager wm;

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_RES_PIN, INPUT_PULLUP);
  bool res;
}

void loop() {
  // Check if the reset button is pressed
  if (digitalRead(TRIGGER_RES_PIN) == LOW) {
    wm.resetSettings();
    wm.setConfigPortalTimeout(timeout);
    wm.startConfigPortal("AutoConnectAP", "12345678"); // Start Config Portal
    Serial.println("Config portal started");
  }

  if (!WiFi.isConnected()) {
    Serial.println("Failed to connect and hit timeout");
    ESP.restart();
    delay(2000);
  }

  Serial.println("connected...yeey :)");
}
