#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN       12 // pin connectd to the LED Strip (GPIO12)
#define NUMPIXELS 10 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500


void Set_Color_Red (uint16_t Outside_Brightness){ // set LED strip color to red
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.setPin(12);
  pixels.begin();
  pixels.setBrightness(255 * Outside_Brightness / 19456); // Maximum LED Brightness multiplied by the input value from I2C, divided by the maximum input value sent by the I2C
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }
}

void Set_Color_Yellow(uint16_t Outside_Brightness){ // set LED strip color to yellow
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.setPin(12); // set affected pin
  pixels.begin();
  pixels.setBrightness(255 * Outside_Brightness / 19456); // Maximum LED Brightness multiplied by the input value from I2C, divided by the maximum input value sent by the I2C
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(255, 255, 0)); // yellow color set
    pixels.show();
  }
}

