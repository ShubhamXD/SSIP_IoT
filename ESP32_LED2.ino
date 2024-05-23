#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
#define BLYNK_TEMPLATE_ID "TMPL3Gt9Gqx7H"
#define BLYNK_TEMPLATE_NAME "IOT"
#define BLYNK_AUTH_TOKEN "3Wo7VMQKmdjPoe-p2AoPR9mOLYTA72X2"
char auth[] = "";

// Your WiFi credentials.
char ssid[] = "";
char pass[] = "";

// Virtual pin to control the LED.
#define LED_PIN 2


// This function will be called every time the virtual pin V1 state changes
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Get the value of the V1 pin

  // If pinValue is HIGH, turn on the LED; otherwise, turn it off
  digitalWrite(LED_PIN, pinValue);
}

void setup() {
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass,"blynk.cloud",80);
  
  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Blynk.run();
}
