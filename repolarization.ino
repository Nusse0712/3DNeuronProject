#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define LED_PIN    13
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    100

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

DEFINE_GRADIENT_PALETTE (heatmap_gp) {
 0, 155, 90, 21, //orange from depolarization
 30, 155, 90, 21, //orange
60, 255, 255, 255, //white
75, 255, 255, 255, //white
100, 155, 90, 21, //white
145, 155, 90, 21, //orange
165, 155, 90, 21, //orange
185, 255, 255, 255, //white
195, 255, 255, 255, //white
220, 155, 90, 21, //orange
255, 155, 90, 21 //orange
};
CRGBPalette16 myPal = heatmap_gp;
void setup() {
   FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.setBrightness(100);

}

void loop() {
   fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
  //leds, nLEDS, startIndex, indexDelta, palette, brightness, blendType
  FastLED.show();

  EVERY_N_MILLISECONDS(25){
    paletteIndex++;
    }
}
