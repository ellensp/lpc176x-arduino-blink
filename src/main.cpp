#include <Arduino.h>

#include "usb_cdc.h"
#include <CDCSerial.h>

#define off 0
#define on 1

#define LED1 P1_18 //on Azteeg x5 mini
#define LED2 P1_20 //on Azteeg x5 mini
#define LED3 P1_19 //on Azteeg x5 mini
#define LED4 P1_21 //on Azteeg x5 mini

#define FAN0 P2_03 //on skr 14 

#define LED_BUILTIN FAN0

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
int ledstate = off;

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  usb_cdc_init();
  UsbSerial.println("Starting...");
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval && ledstate == off) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // set the LED with the ledState of the variable:
    UsbSerial.println("LED On");
    digitalWrite(LED_BUILTIN, HIGH);  
    ledstate = on;
  }

  if (currentMillis - previousMillis >= interval && ledstate == on) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // set the LED with the ledState of the variable:
    UsbSerial.println("LED Off");
    digitalWrite(LED_BUILTIN, LOW);
    ledstate = off;  
  }

  usb_cdc_idle();
}

