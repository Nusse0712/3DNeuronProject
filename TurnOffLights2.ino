#include <FastLED.h>

#define NUM_LEDS  100
#define LED_PIN   12

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

CRGBPalette16 myPal = blackPalette1;
CRGBPalette16 myPal2 = blackPalette2;


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(0);
}

void loop() {
  fill_solid(particleLEDS, NUM_LEDS, CRGB::Black);
  fill_solid(StateLEDS, NUM_LEDS, CRGB::Black);

  FastLED.show();
}
