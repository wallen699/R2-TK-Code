#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define FRONTPIN 4
#define REARPIN 3

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
Adafruit_NeoPixel frontspin = Adafruit_NeoPixel(16, FRONTPIN, NEO_RGBW + NEO_KHZ800);
Adafruit_NeoPixel rearspin = Adafruit_NeoPixel(16, REARPIN, NEO_RGBW + NEO_KHZ800);

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

  Serial.begin(9600);

  frontspin.begin();
  frontspin.show(); // Initialize all pixels to 'off'

 rearspin.begin();
 rearspin.show(); // Initialize all pixels to 'off'

  vents.begin();
  vents.setBrightness(255);
  vents.show(); // Initialize all pixels to 'off'
  
  slot.begin();
  slot.setBrightness(128);
  slot.show(); // Initialize all pixels to 'off'

    //Serial.println(frontspin.numPixels());

}
// G R B W

void loop() {

  FrontSpinner();
  RearSpinner();
  vents_colour(red,green);
    //slot_dot_up(blue,50);
    //slot_dot_down(blue,50);
    slot_dot_bounce(blue,10);
  
  //10 is fast
  delay(10);
}
