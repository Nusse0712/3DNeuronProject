
#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define LED_PIN    13
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    100

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;
//needs two depolarization functions 155, 90, 21
DEFINE_GRADIENT_PALETTE (heatmap_gp) {
 0, 255, 0, 0, //red
 30, 255, 0, 0, //red
60, 0, 0, 0, //dark red
75, 0, 0, 0, //dark red
125, 255, 0, 0,//red
145, 255, 0, 0, //red
165, 255, 0, 0, //red
185, 0, 0, 0, //dark red
195, 0, 0, 0, //dark red
220, 255, 0, 0, //red
255, 255, 0, 0 //red
};

CRGBPalette16 myPal = heatmap_gp;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(255);
}

void loop() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
  //leds, nLEDS, startIndex, indexDelta, palette, brightness, blendType
  FastLED.show();

  EVERY_N_MILLISECONDS(10){
    paletteIndex++;
    }

}
