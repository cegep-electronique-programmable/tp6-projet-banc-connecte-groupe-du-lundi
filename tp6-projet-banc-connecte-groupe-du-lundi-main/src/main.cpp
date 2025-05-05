#include <Arduino.h>
#include "affichage.h"
#include <DEL_Control.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // if(GPIO_PIN_SOURCE_GET(3) == '1'){
    Set_Color_Red();
  // }
  if(GPIO_PIN_SOURCE_GET(3) == '0'){
    Set_Color_Yellow();
  }
}