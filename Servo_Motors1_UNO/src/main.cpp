// Set up the servo motor
#include "main.h"
Servo myServo1;
Servo myServo2;


void setup() {
  // put your setup code here, to run once:
pinMode(vert, INPUT);  // the vertical buttons of the joy
pinMode(Horz, INPUT);  // the horizontal buttons of the joy
pinMode(Sw, INPUT);
pinMode(LedPin, OUTPUT);
pinMode(Buzer, OUTPUT);
myServo1.attach(myServoPin1);
myServo2.attach(myServoPin2);
digitalWrite(Sw, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
myServo1.write(180.0/1023.*analogRead(vert)); //Position of the horn
myServo2.write(180.0/1023.*analogRead(Horz)); //Position of the horn
delay(10);
// The Vertical potentiometer of the joyatick to the buzer
if (180./1023*analogRead(vert)>=180){
tone(Buzer, 180./1023*analogRead(Horz)+50, 10);
}

if (180./1023*analogRead(vert)<90){
tone(Buzer, 180./1023*analogRead(Horz)+100, 10);
}
// The horizontal potentiometer of the joystick to the buzer
if (180./1023*analogRead(Horz)>=180){
tone(Buzer, 180./1023*analogRead(Horz)+200, 10);
}

if (180./1023*analogRead(Horz)<90){
tone(Buzer, 180./1023*analogRead(Horz)+300, 10);
}

// The switch in the center of the joystick
if (digitalRead(Sw)==0){ 
 tone(Buzer, 800, 10); 
digitalWrite(LedPin, HIGH);
delay(100);
digitalWrite(LedPin, LOW);}
}

