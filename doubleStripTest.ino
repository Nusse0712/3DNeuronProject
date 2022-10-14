#include <FastLED.h> 

FASTLED_USING_NAMESPACE

#define STATE_PIN         13
#define PARTICLE_PIN      12
#define LED_TYPE     WS2812B
#define NUM_LEDS 150
#define NUM_LED  250
int fadeAmount = 3; 
int brightness = 0; 
uint8_t paletteIndex = 0;


CRGBPalette16 purplePalette = CRGBPalette16(
                                CRGB::DarkViolet,
                                CRGB::DarkViolet,
                                CRGB::Green,
                                CRGB::Green,

                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,

                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,
                                CRGB::Green,

                                CRGB::Green,
                                CRGB::Green,
                                CRGB::DarkViolet,
                                CRGB::DarkViolet
                               
                              );
CRGBPalette16 myPal = purplePalette;

CRGB stateLeds[NUM_LEDS]; 
CRGB partLeds[NUM_LED]; 

void restingState(){
  for(int i = 0; i < NUM_LEDS; i++ )
   {
    
   stateLeds[i].setRGB(172,250,245);
   //stateLeds[i].setRGB(243,207,198);
   stateLeds[i].fadeLightBy(brightness);
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
  void particles(){
     EVERY_N_MILLISECONDS(10){
    
    partLeds[random8(0, NUM_LED-1)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
        partLeds[random8(0, NUM_LED-1)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
       
    //can also use CRGB::Green to represent the sodium
    
    }
    EVERY_N_MILLISECONDS(50){
       stateLeds[random8(0, NUM_LEDS-1)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
       stateLeds[random8(0, NUM_LEDS-1)] = ColorFromPalette(myPal, random8(), 255, LINEARBLEND);
      }
    fadeToBlackBy(stateLeds, NUM_LEDS, 1);
    fadeToBlackBy(partLeds, NUM_LED, 10);

    FastLED.show();
  
    }

    void resting(){
      restingState(); 
      particles(); 
      }
void setup() {
  FastLED.addLeds<WS2812B, STATE_PIN, GRB>(stateLeds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, PARTICLE_PIN, GRB>(partLeds, NUM_LED).setCorrection(TypicalLEDStrip); 
  FastLED.setBrightness(80);
 
}

void loop() {
  resting();
     FastLED.show();
}
