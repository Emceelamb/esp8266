#include <Adafruit_NeoPixel.h>

#define LED_PIN 13
#define LED_COUNT 35

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  pinMode(0, INPUT);

  Serial.print("Hello World");
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop() {
  int slider = analogRead(0);
  slider = 1023 - slider;
  Serial.print(slider);

  colorWipe(strip.Color(255, 0, 255), 50);
}

void colorWipe(uint32_t color, int wait){
  for(int i = 0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}