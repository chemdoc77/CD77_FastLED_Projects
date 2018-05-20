#ifndef Time_performance.h
#define Time_performance.h

/*
 
 Based on the Time Performance sketch by Mark Kriegsman of FastLED at:
 https://gist.github.com/kriegsman/a916be18d32ec675fea8
 
*/


#define TC(HOURS,MINUTES,SECONDS) \
  ((uint32_t)(((uint32_t)((HOURS)*(uint32_t)(3600000))) + \
  ((uint32_t)((MINUTES)*(uint32_t)(60000))) + \
  ((uint32_t)((SECONDS)*(uint32_t)(1000)))))


#define AT(HOURS,MINUTES,SECONDS) if( atTC(TC(HOURS,MINUTES,SECONDS)) )
#define FROM(HOURS,MINUTES,SECONDS) if( fromTC(TC(HOURS,MINUTES,SECONDS)) )

static bool atTC( uint32_t tc)
{
  bool maybe = false;
  if( gTimeCode >= tc) {
    if( gLastTimeCodeDoneAt < tc) {
      maybe = true;
      gLastTimeCodeDoneAt = tc;
    }
  }
  return maybe;
}

static bool fromTC( uint32_t tc)
{
  bool maybe = false;
  if( gTimeCode >= tc) {
    if( gLastTimeCodeDoneFrom <= tc) {
      maybe = true;
      gLastTimeCodeDoneFrom = tc;
    }
  }
  return maybe;
} 

void RestartPerformance()
{
  gLastTimeCodeDoneAt = 0;
  gLastTimeCodeDoneFrom = 0;
  gTimeCodeBase = millis();
}


void Performance()
{
 FROM(0,0,00.000)     {cd77_arrayfill_RWB_all_one_color_no_rep(450);} // lights up the whole strip with one color at a time and repeats z times.
 FROM(0,0,05.000)     {cd77_arrayfill_RWB_all(450, 80); }//lights up each segment and keeps it on until the end of the animation.
 FROM(0,0,12.000)     {cd77_arrayfill_RWB_each_alone(450, 80); }// lights up each segment and keeps it on until the end of the animation.
 FROM(0,0,18.000)     {cd77_arrayfill_RWB_all_each_array_together_no_rep(450, 80);fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.delay(450);} // flashing of all color segments
 FROM(0,0,24.000)     {cd77_arrayfill_RWB_all_each_array_together_no_delay(80);}  //all color segments are on 
 FROM(0,0,27.000)     {fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.delay(50);}
 FROM(0,0,27.500)     {CD77_chase_array_color_symet(400,400,4); FastLED.delay(50);} //chase pattern of red black white black blue black
 FROM(0,0,42.000)     {CD77_chase_array_color_symet(400,400,8); FastLED.delay(50);} //chase pattern red white blue
 FROM(0,0,57.000)     {fill_solid(leds, NUM_LEDS, CRGB::Black);FastLED.delay(50); }
 AT(0,0,57.500)       {RestartPerformance(); }
}
#endif
