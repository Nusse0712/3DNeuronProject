#include <FastLED.h>

FASTLED_USING_NAMESPACE

#define STATE_PIN    13
#define PART_PIN     12
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    150
#define FRAMES_PER_SECOND  120

int RestfadeAmount = 3; 
int Restbrightness = 0; 

int HypfadeAmount = 8; 
int Hypbrightness = 0; 

CRGB leds[NUM_LEDS];
CRGB partLeds[NUM_LEDS];
uint8_t paletteIndex = 0;
char command;
boolean newData = false;

CRGBPalette16 hypGreenPal = CRGBPalette16 (
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Green,
                               CRGB::Black,
                               CRGB::Green,
                               CRGB::Green
                             );
CRGBPalette16 repolPurplePal = CRGBPalette16(
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
CRGBPalette16 repolGreenPal = CRGBPalette16 (
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
CRGBPalette16 depoPurpPal = CRGBPalette16(
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Black,
                               CRGB::Black,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet,

                               CRGB::Green,
                               CRGB::Green,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet
                                
                              );
                          
CRGBPalette16 restingGreenPal = CRGBPalette16 (
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,
                               CRGB::Black,

                               CRGB::Green,
                               CRGB::Black,
                               CRGB::DarkViolet,
                               CRGB::DarkViolet
                             );
                             
CRGBPalette16 restingPurpPal = CRGBPalette16(
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



CRGBPalette16 earlyDepoPal = CRGBPalette16 (
        CRGB::White, 
        CRGB::White, 
        CRGB::Goldenrod,
        CRGB::Goldenrod, 

        CRGB::Goldenrod, 
        CRGB::Orange, 
        CRGB::Orange, 
        CRGB::Goldenrod, 

        CRGB::Goldenrod,
        CRGB::White, 
        CRGB::White,
        CRGB::Goldenrod, 

        CRGB::Goldenrod, 
        CRGB::Orange, 
        CRGB::Orange,
        CRGB::Goldenrod  
  );


CRGBPalette16 lateDepoPal = CRGBPalette16 (
  CRGB::Orange,
  CRGB::DarkOrange,
  CRGB::DarkOrange, 

  CRGB::DarkOrange,
  CRGB::Black, 
  CRGB::DarkOrange, 

  CRGB::Orange,
  CRGB::DarkOrange, 
  CRGB::DarkOrange,
  
  CRGB::DarkOrange,
  CRGB::Black, 
  CRGB::DarkOrange,  

  CRGB::Orange,
  CRGB::DarkOrange, 
  CRGB::DarkOrange,

  CRGB::Black
  );
  



CRGBPalette16 repolarPal = CRGBPalette16 (
        CRGB::Orange, 
        CRGB::Goldenrod, 
        CRGB::Goldenrod,
        CRGB::Goldenrod, 

        CRGB::Goldenrod, 
        CRGB::White, 
        CRGB::White, 
        CRGB::White, 

        CRGB::Orange,
        CRGB::Goldenrod, 
        CRGB::Goldenrod,
        CRGB::Goldenrod, 

        CRGB::Goldenrod, 
        CRGB::White, 
        CRGB::White,
        CRGB::White  
  );

 int period =  10000;  
 

void setup() {
  
  Serial.begin(9602); 
  FastLED.addLeds<WS2812B, STATE_PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2812B, PART_PIN, GRB>(partLeds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(80);

}

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { restingState,earlyDepolarization,lateDepolarization, repolarization, hyperpolarization};
uint8_t gCurrentPatternNumber = 0;

void loop() {
  recieveChar(); 
  commandLight();
}
void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}
void recieveChar(){
  if(Serial.available() > 0){
    command = Serial.read(); 
    Serial.println(command);
    serialFlush();
    newData = true;
    }
  }
 
void commandLight(){
  if(newData == true){

    if (command == 'A') { 
        for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){  
         lightShowStrip();
        }
      }else
       if(command == 'R'){
       for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){  
          restingState();
              
       }  
      } else if(command == 'E'){
           for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
             earlyDepolarization();
           }
      } else if(command == 'L'){
         for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){  
             lateDepolarization();
         }      
        }else if(command == 'H'){
          for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
             hyperpolarization();
          }
               
            
        } else if(command == 'P'){
            for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
             repolarization();
            }
        } 
    offStrip();
    newData = false; 
    }
  
  }
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}





void restingStateStrip(){
  for(int i = 0; i < NUM_LEDS; i++ )
   {
    
   leds[i] = CRGB::White;
   leds[i].fadeLightBy(Restbrightness);
  }
  FastLED.show();
  Restbrightness = Restbrightness + RestfadeAmount;
  // reverse the direction of the fading at the ends of the fade: 
  if(Restbrightness == 0 || Restbrightness == 255)
  {
    RestfadeAmount = -RestfadeAmount ; 
  }    
  delay(9);
  }

void earlyDepoStrip(){
   fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, earlyDepoPal, 255, LINEARBLEND);
  //leds, nLEDS, startIndex, indexDelta, palette, brightness, blendType
  FastLED.show();

  EVERY_N_MILLISECONDS(15){
    paletteIndex++;
    }
  
  }

void lateDepoStrip(){
   fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, lateDepoPal, 255, LINEARBLEND);
  //leds, nLEDS, startIndex, indexDelta, palette, brightness, blendType
  FastLED.show();

  EVERY_N_MILLISECONDS(10){
    paletteIndex++;
    }
  }

void repolarizationStrip(){
 fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, repolarPal, 255, LINEARBLEND);
  //leds, nLEDS, startIndex, indexDelta, palette, brightness, blendType
  FastLED.show();

  EVERY_N_MILLISECONDS(25){
    paletteIndex++;
    } 
  }

void hyperpolarizationStrip(){
   for(int i = 0; i < NUM_LEDS; i++ )
   {
    
   leds[i].setRGB(255,255,255);
   leds[i].fadeLightBy(Hypbrightness);
  }
  FastLED.show();
  Hypbrightness = Hypbrightness + HypfadeAmount;
  // reverse the direction of the fading at the ends of the fade: 
  if(Hypbrightness == 0 || Hypbrightness == 100)
  {
    HypfadeAmount = -HypfadeAmount ; 
  }    
  delay(4);
  
  }
void Particles(CRGBPalette16 pal1,CRGBPalette16 pal2){
   EVERY_N_MILLISECONDS(20) {
    //Switch on an LED at random, choosing a random color from the palette
    partLeds[random8(0, NUM_LEDS - 50)] = ColorFromPalette(pal1, random8(), 255, LINEARBLEND);
  }

  EVERY_N_MILLISECONDS(20) {
    //Switch on an LED at random, choosing a random color from the palette
    partLeds[random8(51, NUM_LEDS)] = ColorFromPalette(pal2, random8(), 255, LINEARBLEND);
  }

  // Fade all LEDs down by 1 in brightness each time this is called
  fadeToBlackBy(partLeds, NUM_LEDS, 1);

  FastLED.show();
  }

  void restingState(){


    restingStateStrip(); 
    Particles(restingPurpPal,restingGreenPal);
 
    }

  void earlyDepolarization(){

    earlyDepoStrip();
    Particles(depoPurpPal,restingGreenPal);

 
    }
  void lateDepolarization(){

    lateDepoStrip(); 
    Particles(depoPurpPal,restingGreenPal);
  
 
    }
   void repolarization(){
    
  

    repolarizationStrip(); 
    Particles(repolPurplePal,repolGreenPal);
 
    
    }
    void hyperpolarization(){
   
 
     hyperpolarizationStrip(); 
     Particles(restingPurpPal,hypGreenPal);
 
     
      }
     
    void lightShowStrip(){
       gPatterns[gCurrentPatternNumber]();
       FastLED.delay(1000/FRAMES_PER_SECOND);
       EVERY_N_SECONDS( 10 ) { nextPattern(); } 
      }

      void offStrip(){
            fill_solid(leds, NUM_LEDS, CRGB::Black);
            fill_solid(partLeds, NUM_LEDS, CRGB::Black);
            FastLED.show();
  }
    

  

  



  
