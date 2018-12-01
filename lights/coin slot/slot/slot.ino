#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define VENT_PIN 6
#define SLOT_PIN 5

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

Adafruit_NeoPixel vents = Adafruit_NeoPixel(2, VENT_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel slot = Adafruit_NeoPixel(6, SLOT_PIN, NEO_GRB + NEO_KHZ800);

uint32_t magenta = vents.Color(255, 0, 255);
uint32_t red = vents.Color(255, 0, 0);
uint32_t green = vents.Color(0, 255, 0);
uint32_t blue = vents.Color(0, 0, 255);
uint32_t yellow = vents.Color(255, 255, 0);


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  vents.begin();
  vents.setBrightness(255);
  vents.show(); // Initialize all pixels to 'off'
  
  slot.begin();
  slot.setBrightness(128);
  slot.show(); // Initialize all pixels to 'off'
}
//R B W

void loop() 
{
  // Some example procedures showing how to display to the pixels:
  //DotA(strip.Color(128, 0, 0), 200); // Red 
 // vents_off();
 // slot_off();
 // delay(500);
  vents_colour(red,green);
  slot_dot_up(blue,50);
  slot_dot_down(blue,50);

//  delay(500);
  
}

void vents_colour(uint32_t tcolour,uint32_t bcolour)
{
   vents.setPixelColor(0, tcolour);
    vents.setPixelColor(1, bcolour);
   
    //Display
    vents.show();
}


void vents_off()
{
       
   vents.setPixelColor(0, 0);
    vents.setPixelColor(1, 0);
   
    //Display
    vents.show();
}

void slot_off()
{
    //Clear All pixels
    for (uint16_t ii=0; ii < slot.numPixels(); ii++)
    {
        slot.setPixelColor(ii, 0);        //turn every  pixel off
    }
    //Display
    slot.show();
}

void slot_colour(uint32_t colour)
{
    //Set All pixels
    for (uint16_t ii=0; ii < slot.numPixels(); ii++)
    {
        slot.setPixelColor(ii, colour);        //turn every  pixel off
    }
    //Display
    slot.show();
}

// Fill the dots one after the other with a color
void slot_dot_down(uint32_t c, uint8_t wait)
{
  for(uint16_t i=0; i<slot.numPixels(); i++)
  {
    //Clear All pixels
    slot_off();
    
    //Set Pixel
    slot.setPixelColor(i, c);
    
    //Display
    slot.show();
    
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void slot_dot_up(uint32_t c, uint8_t wait)
{
  for(uint16_t i=slot.numPixels()+1;i>0; i--)
  {
    //Clear All pixels
    slot_off();
    
    //Set Pixel
    slot.setPixelColor(i-1, c);
    
    //Display
    slot.show();
    
    delay(wait);
  }
}
void DotA(uint32_t c, uint8_t wait)
{
  //for(uint16_t i=strip.numPixels()+1; i>0; i--)
  {
    //Clear All pixels
  //  for (uint16_t ii=0; ii < strip.numPixels(); ii++)
    {
   //     strip.setPixelColor(ii, 0);        //turn every  pixel off
    }
    
    //Set Pixel
   // strip.setPixelColor(i-1, c);
    
    //Display
    //strip.show();
    
  //  delay(wait);
  }
}
