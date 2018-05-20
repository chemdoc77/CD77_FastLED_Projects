#ifndef Chase.h
#define Chase.h

/* The chase code functions are inspired and partially based on code by Zaphod Beeblewurdle in:

https://plus.google.com/107029944060954069417/posts/6r7QakiLLvm

and inspired and partially based on code by Jason Coon’s Color Pulse in:

https://plus.google.com/+JasonCoon1/posts/gpN7pEqRQUe

*/

int leds_done = 0;
uint16_t x=0;
uint16_t wait = 800;
uint16_t i=0;
uint8_t dotnumber=3;
uint8_t colorIndex =0;

CRGB colorarry2[]=  {CRGB::Red,CRGB::Grey, CRGB::Blue}; // color array for the chase functions

CRGB Array_color2= colorarry2[0];
uint8_t Array_Size2 = ARRAY_SIZE(colorarry2);


CRGB Color2=CRGB::Red;



//========================Functions=========================


// symetrical single color chase sequence:

void CD77_chase_one_color_symet(CRGB color_one, uint16_t wait1, uint8_t dots ) {
//color_one is color of pixels, wait is the time period between the chase segment, dots are the number of pixels in a chase segment.  
//shift pixels
for(int i =  NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
    
Dot_time.setPeriod( wait1 );
 leds_done = 0;

}

if(leds_done <dots) {
leds[0] = color_one; 
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;

  }
 }

 
// symetrical mult color chase sequence:

void CD77_chase_array_color_symet(uint16_t wait1,uint16_t wait_Array , uint8_t dots ) { 
// wait1 is the time period between the chase segment, wait_Array is the time period between new colors used in the colorarray, dots are the number of pixels in a chase segment.  
  
//shift pixels

EVERY_N_MILLIS_I( Array_time, 500){ 
  Array_time.setPeriod( wait_Array );
  i++;
  if (i > Array_Size2-1) {i = 0;}
  Array_color2 = colorarry2[i];
  }

for(int i =  NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
 Dot_time.setPeriod( wait1 );
 leds_done = 0;
}

if(leds_done <dots) {
leds[0] = Array_color2;
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;

  }

 }


// one color unsymetrical chase sequence:

void CD77_chase_one_color_unsymet(CRGB color_one, uint16_t wait1, uint16_t wait2,uint8_t dots ) { // one color unsymetrical chase sequence
//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
Dot_time.setPeriod( random16(wait1,wait2) );
leds_done = 0;
}

if(leds_done <dots) {
leds[0] = color_one; 
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;
  }
 }


 
//multi color unsymetrical chase sequence:

void CD77_chase_array_color_unsymet(uint16_t wait1, uint16_t wait2,uint16_t wait_Array, uint8_t dots ) {//multi color unsymetrical chase sequence

EVERY_N_MILLIS_I( Array_time, 500){ 
  Array_time.setPeriod( wait_Array );
  i++;
  if (i > Array_Size2-1) {i = 0;}
  Array_color2 = colorarry2[i];
  }

//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 200) {
 Dot_time.setPeriod( random16(wait1,wait2) );
 leds_done = 0;

}

if(leds_done <dots) {
leds[0] = Array_color2; //colorarry[i];
leds_done = leds_done + 1;
} else {
leds[0] = CRGB::Black;
  }
 }




 
#endif  
