// #include <Adafruit_NeoPixel.h>
// #ifdef __AVR__
//   #include <avr/power.h>
// #endif
// #define PIN       16
// #define NUMPIXELS 16

// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// #define DELAYVAL 500

// void setup() {
//   pixels.begin();
//   pixels.show();
//   pixels.setPin(16);
//   pixels.setBrightness(255);
// }

// void loop() {
//   pixels.setPixelColor(0,pixels.Color(255,0,0));
  
// }
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN       1
#define NUMPIXELS 10
void Set_Color_Red (void);
void Set_Color_Yellow(void);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

// void loop() {
//   Set_Color_Red();
//   delay(1000);
//   Set_Color_Yellow();
//   delay(1000);
// }


void Set_Color_Red (void){
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.setPin(1);
  pixels.begin();
  pixels.setBrightness(50);
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }
}

void Set_Color_Yellow(void){
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.setPin(1);
  pixels.begin();
  pixels.setBrightness(50);
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 255, 0));
    pixels.show();
  }
}