#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define LED_PIN    13
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    300
int fadeAmount = 7; 
int brightness = 0; 
CRGB leds[NUM_LEDS];

void setup() {
 FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
 
 FastLED.setBrightness(80);

}

void loop() {
   for(int i = 0; i < NUM_LEDS; i++ )
   {
    
   leds[i].setRGB(255,255,255);
   leds[i].fadeLightBy(brightness);
  }
  FastLED.show();
  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade: 
  if(brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount ; 
  }    
  delay(9);

}
