#include "Bridge.h"
#include "Config.h"
#include <FastLED.h>
#include <Arduino.h>


CRGB leds[1];

void setup() {
  FastLED.addLeds<WS2812, LED_NEOPIXEL, GRB >(leds, 1);
  Serial.begin(115200);

  leds[0] = CRGB::Red;
  FastLED.show();

  delay(1000);
  leds[0] = CRGB::Orange;
  FastLED.show();

  Serial.println();
  Serial.println("╔════════════════════════════════════════════════╗");
  Serial.println("║  ESP32-S3 USB to BLE Keyboard Bridge           ║");
  Serial.println("║  Supports keyboard + multi-device              ║");
  Serial.println("╚════════════════════════════════════════════════╝");
  Serial.println();

  leds[0] = CRGB::Yellow;
  FastLED.show();

  if (LED_FEEDBACK_PIN >= 0) {
    pinMode(LED_FEEDBACK_PIN, OUTPUT);
    digitalWrite(LED_FEEDBACK_PIN, LOW);
  }

  Bridge::begin();

  Serial.println();
  Serial.println("╔════════════════════════════════════════════════╗");
  Serial.println("║  READY - Connect USB devices via hub           ║");
  Serial.println("╚════════════════════════════════════════════════╝");
  Serial.println();
}

void loop() {
  bool connected = Bridge::loop();
  if (connected)
    leds[0] = CRGB::Blue;
  else
    leds[0] = CRGB::Green;
  FastLED.show();
  delay(10);
}
