#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include <Wire.h>


#define VENT_PIN 9
#define SLOT_PIN 8

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

  Wire.begin(11);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

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
  //vents_colour(red,green);
  slot_dot_up(blue,50);
  slot_dot_down(blue,50);

//  delay(500);
  
}

void receiveEvent(int howMany) {
  //while (1 < Wire.available()) { // loop through all but the last
  //  char c = Wire.read(); // receive byte as a character
  //  Serial.print(c);         // print the character
  //}
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer

  switch (x) {
  case 2:
    vents_off();
    slot_off;
  break;
  case 4:
    vents_colour(red,red);
    break;
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
