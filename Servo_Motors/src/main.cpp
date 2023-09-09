/*
  ESP32 Servo
  Use LED on GPIO2
  Use Servo on GPIO2
*/
#include <ESP32Servo.h>
#define ServoPin 2  // Define the pin position of the Servo
Servo my_Servo;     // Create an object of the servo 
// LED on GPIO2
int ledPin = 15;    // Use LED on GPIO2
int Buzer  =4;


void setup()
{
    // Start the serial 
    Serial.begin(115200);
    // Set LED as output
    pinMode(ledPin, OUTPUT);
    my_Servo.attach(ServoPin);    // Set the Servo by attaching its pin to your object my_Servo
    pinMode(Buzer, OUTPUT);
    // Serial monitor setup
    Serial.begin(115200);
}

void loop()
{
   
    for(int pos=0; pos<=180; pos+=20){   // Move the horn og the Servo from to 0 to 180 with a step of 20
       my_Servo.write(pos);
       if(digitalRead(ServoPin)==0){         // If the servo moves light up the LED
          digitalWrite(ledPin, HIGH);
       }
       tone(Buzer, 5*pos+200, 10);       // Emit a tone from the buzer correcponding to the Servo position
       delay(500);
      digitalWrite(ledPin, LOW);
      delay(100);

     }
     
}