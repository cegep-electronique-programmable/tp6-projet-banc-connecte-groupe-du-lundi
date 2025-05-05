#include <Arduino.h>
#include "affichage.h"
#include "capteurs.cpp"

int nbrPhoneCharge = 0;
int nbrPersonne = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);                      // start serial for output
  Wire.begin(SDA, SCL, I2C_MASTER);  // join i2c bus (address optional for master)
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for 1second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(100);                      // wait for 100ms

  capteurRead();
}