/**
 * Program: pwm
 * Purpose:
 *   A basic program to control a motor via the Arduino PWM feature.
 *   Notes:
 *   1) analogWrite() is an inbuilt function used to provide pwm on a pin
 *   2) pwm is available on the nano as follows;
 *      Board           || PWM Pins           || PWM Frequency
 *      Uno, Nano, Mini || 3, 5, 6, 9, 10, 11 || 490 Hz (pins 5 and 6: 980 Hz)
 *   3) Warning: The PWM outputs generated on pins 5 and 6 will have higher-
 *      than-expected duty cycles. This is because of interactions with the 
 *      millis() and delay() functions, which share the same internal timer 
 *      used to generate those PWM outputs. This will be noticed mostly on low 
 *      duty-cycle settings (e.g. 0 - 10) and may result in a value of 0 not 
 *      fully turning off the output on pins 5 and 6.
 * @author: David Argles, d.argles@gmx.com
 */

/* Program identification */ 
#define PROG    "pwm"
#define VER     "1.0"
#define BUILD   "13apr2021 @23:13h"

/* Necessary includes */
#include "flashscreen.h"

/* Global "defines" - may have to look like variables because of type */
#define BAUDRATE    115200     // Baudrate for serial output
#define MOTOR_PIN   3
#define ANALOGUE_IN A0

/* ----- Initialisation ------------------------------------------------- */

/* Global stuff that must happen outside setup() */
flashscreen flash;
int reading = 0;

void setup() {
  Serial.begin(BAUDRATE);           // Start up the serial output port
  // Serial.setDebugOutput(true);
  flash.message(PROG, VER, BUILD);  // Send program details to serial output

  // put your setup code here, to run once:
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(ANALOGUE_IN);    // read the input pin
  analogWrite(ANALOGUE_IN, reading/4);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}
