#ifndef Array_Functions.h
#define Array_Functions.h



//================ New Functions for RGBSet Arrays =====================

void cd77_arrayfill_RWB_all_one_color_no_rep(uint16_t wait){
  
 
   for ( xca=0; xca<3; xca++){
  fill_solid( leds, NUM_LEDS, colorarray[xca]);
   FastLED.delay(wait);
   fill_solid( leds, NUM_LEDS, CRGB::Black);
   FastLED.delay(wait);
    }
 
}

void cd77_arrayfill_RWB_all(uint16_t wait, uint16_t numberinarray){
  
   for ( xca=0; xca<3; xca++){
  fill_solid(ledarray[xca], numberinarray, colorarray[xca]);
   FastLED.delay(wait);
   }
   fill_solid( leds, NUM_LEDS, CRGB::Black);
   FastLED.delay(wait);
   
   
}

void cd77_arrayfill_RWB_each_alone(uint16_t wait, uint16_t numberinarray){
  
  for ( xca=0; xca<3; xca++){
  fill_solid(ledarray[xca], numberinarray, colorarray[xca]);
   FastLED.delay(wait);
 
   fill_solid( ledarray[xca], numberinarray, CRGB::Black);
   FastLED.delay(wait/2);//FastLED.show();
    }
   
}


void cd77_arrayfill_RWB_all_each_array_together_no_rep(uint16_t wait, uint16_t numberinarray){
  
   for ( xca=0; xca<3; xca++){
  fill_solid( ledarray[xca],  numberinarray, colorarray[xca]);
   }
   FastLED.delay(wait);
   //fill_solid( leds, NUM_LEDS, CRGB::Black);
    // FastLED.delay(wait);
   
}

void cd77_arrayfill_RWB_all_each_array_together_no_delay(uint16_t numberinarray){
  
   for ( xca=0; xca<3; xca++){
  fill_solid( ledarray[xca],  numberinarray, colorarray[xca]);
   }
   FastLED.show();  
}




 
#endif  
