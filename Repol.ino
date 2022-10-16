#include <FastLED.h>

#define NUM_LEDS  100
#define LED_PIN   12

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

CRGBPalette16 purplePalette = CRGBPalette16(
                                CRGB::Green,
                               CRGB::Green,
                               CRGB::Green,
                               CRGB::Green,

                               CRGB::DarkViolet,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet,

                               CRGB::DarkViolet,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet,

                               CRGB::DarkViolet,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet
                                
                              );

CRGBPalette16 greenPalette = CRGBPalette16 (
                                CRGB::Black,
                                CRGB::Black,
                                CRGB::Black,
                                CRGB::Black,

                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,

                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,
                                CRGB::DarkViolet,

                                CRGB::Black,
                                CRGB::Black,
                                CRGB::Black,
                                CRGB::DarkViolet
                             );


CRGBPalette16 myPal = purplePalette;
CRGBPalette16 myPal2 = greenPalette;


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {

  EVERY_N_MILLISECONDS(20) {
    //Switch on an LED at random, choosing a random color from the palette
    leds[random8(0, NUM_LEDS - 50)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
  }

  EVERY_N_MILLISECONDS(20) {
    //Switch on an LED at random, choosing a random color from the palette
    leds[random8(51, NUM_LEDS)] = ColorFromPalette(myPal2, random8(), 255, LINEARBLEND);
  }

  // Fade all LEDs down by 1 in brightness each time this is called
  fadeToBlackBy(leds, NUM_LEDS, 1);

  FastLED.show();
}
