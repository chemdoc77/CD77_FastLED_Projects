// Flagpole Project Code with Chase Animation by Chemdoc77

// Look at the READ_ME.h tab for an explanation of this sketch.


#define FASTLED_ALLOW_INTERRUPTS 0 //use for  WEMOS D1 Mini Pro
#include <FastLED.h>

#define LED_PIN 6  // change to D6 for WEMOS D1 Mini Pro
#define CHIPSET NEOPIXEL 
#define NUM_LEDS 240

#define BRIGHTNESS 40

// RGBSet Arrays 
CRGB rawleds[NUM_LEDS];
CRGBSet leds(rawleds, NUM_LEDS);
CRGBSet leds1(leds(0,79));
CRGBSet leds2(leds(80,159));
CRGBSet leds3(leds(160,239));

struct CRGB * ledarray[] ={leds1, leds2, leds3}; 
CRGB colorarray[]=  {CRGB::Red,CRGB::Grey, CRGB::Blue};


uint16_t xca=0;  // needed so one can use xca outside of a for state
uint16_t numberinarray = 33; //needed so one can use numberinarray outside of a for state
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

//Time Performance code

uint32_t gTimeCodeBase = 0;
uint32_t gTimeCode = 0;
uint32_t gLastTimeCodeDoneAt = 0;
uint32_t gLastTimeCodeDoneFrom = 0;
//===========================================
#include "Array_Functions.h"
#include "Chase.h"
#include "Time_performance.h"
  
void setup() {

delay(1000); // sanity delay
FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS);
FastLED.setBrightness( BRIGHTNESS );
FastLED.setMaxPowerInVoltsAndMilliamps(5,3000);
 set_max_power_indicator_LED(13);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
//Time Performance code
   RestartPerformance();
}

//============================================
void loop() {
//Time Performance code
  gTimeCode = millis() - gTimeCodeBase;  
  Performance();

}

