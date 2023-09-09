/* 
This is the header of all the constants used in the projects
 */
#ifndef CLOBALCONST_H
#define GLOBALCONST_H
#include <Arduino.h>
// Set the pin of both Servo
const int myServoPin1 =5;
const int myServoPin2 =6;
// Setup the buzer
const int Buzer = 12;
// Setup the Joystick which is just tow potentiometers and a switch
const int vert = A0;
const int Horz = A1;
const int Sw   = 2;
// Setup the Led pin
int LedPin = 4;

#endif