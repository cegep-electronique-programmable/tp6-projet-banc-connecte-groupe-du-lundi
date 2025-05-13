#include <Arduino.h>
#include <Wire.h>
#include <PolledTimeout.h>
#include <APDS9930.h>
#include "affichage.h"
#include <DEL_Control.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define DUMP_REGS
//=====================================================================================
//  Le code suivant permet de déterminer si quelqu'un est en train de charger son téléphone,
//  la LED va allume en rouge sinon LED allume en jaune. La luminosité de la lumière va dépendre 
//  de la luminosité capté par le capteur de APDS9930. Le nombre de personne passé est aussi 
//  enregistré et imprimer au terminal a chaque fois qu'une personne est détecté.
//=====================================================================================

// Global Variables
APDS9930 apds = APDS9930();
uint16_t proximity_data = 0;
uint16_t light_data = 0;
int proximity_max = 0;
int light_max = 0;
int nbrPhoneCharge = 0;
int nbrPersonne = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(14, INPUT);
  
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("------------------------"));
  Serial.println(F("APDS-9930 - ProximityLED"));
  Serial.println(F("------------------------"));
  
  // Initialize APDS-9930 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9930 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }
  
  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_1X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }

  // Adjust the Light sensor gain
  if ( !apds.setAmbientLightGain(PGAIN_1X) ) {
    Serial.println(F("Something went wrong trying to set PGAIN"));
  }
  
  // Start running the APDS-9930 proximity sensor (no interrupts)
  if ( apds.enableProximitySensor(false) ) {
    Serial.println(F("Proximity sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during sensor init!"));
  }

#ifdef DUMP_REGS
  /* Register dump */
  uint8_t reg;
  uint8_t val;

  for(reg = 0x00; reg <= 0x19; reg++) {
    if( (reg != 0x10) && \
        (reg != 0x11) )
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif
}


// the loop function runs over and over again forever
void loop() {

  if((digitalRead(14)) == 0){ 
  Set_Color_Red(light_data); // couleur rouge + brightness en fonction de light_data
  }
  if((digitalRead(14)) == 1){
    Set_Color_Yellow(light_data);  // couleur rouge + brightness en fonction de light_data 
  }
  
  // Read the proximity value
  if ( !apds.readProximity(proximity_data) ) {
    Serial.println("Error reading proximity value");
  } else {
    Serial.print("Proximity: ");
    Serial.println(proximity_data);

    // This is an ugly hack to reduce sensor noise.
    // You may want to adjust POFFSET instead.
    /*
    proximity_data -= 200;
    if (proximity_data > 50000) {
      proximity_data = 0;
    }
    if (proximity_data > proximity_max) {
      proximity_max = proximity_data;
    }
    proximity_data = map(proximity_data, 0, proximity_max, 0, 1023);
    */
  }

  // Read the light value of CH0
  if ( !apds.readCh0Light(light_data) ) {
    Serial.println("Error reading light value");
  } else {
    Serial.print("Light: ");
    Serial.println(light_data);
  }
  if (proximity_data == 1023){
    nbrPersonne++;
    Serial.print("Personnes passé: ");
    Serial.println(nbrPersonne);
  }

  
  // Wait 3000 ms before next reading
  delay(120);
}