/*
  ESP32 Servo
  Use LED on GPIO 15
  Use Servo on GPIO 2
  Use Buzer on GPIO 4
*/
#include "main.h"

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo my_Servo;     // Create an object of the servo 

void setup()
{
    // Start the serial 
    Serial.begin(115200);
     if(!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
    }
    delay(10);
    OLED.clearDisplay();
    OLED.setTextSize(2);
    OLED.setCursor(2, 2);
    OLED.setTextColor(WHITE);
    // Set LED as output
    pinMode(LedPin, OUTPUT);
    my_Servo.attach(ServoPin);    // Set the Servo by attaching its pin to your object my_Servo
    pinMode(Buzer, OUTPUT);
   
}

void loop()
{
   
    for(int pos=0; pos<=180; pos+=20){   // Move the horn og the Servo from to 0 to 180 with a step of 20
       my_Servo.write(pos);
        // Display static text
       
       //OLED.println("Angle: ");
       OLED.println(pos);
       OLED.display(); 
       if(digitalRead(ServoPin)==0){         // If the servo moves light up the LED
          digitalWrite(LedPin, HIGH);
       }
       tone(Buzer, 5*pos+200, 10);       // Emit a tone from the buzer correcponding to the Servo position
       delay(500);
      digitalWrite(LedPin, LOW);
      delay(100);
       // Clear the buffer
       OLED.clearDisplay();

     }
     
}