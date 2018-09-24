/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <Wire.h>
#include "Adafruit_VCNL4010.h"
Adafruit_VCNL4010 vcnl;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("VCNL4010 test");
  if (! vcnl.begin()){
    Serial.println("Sensor not found");
    while (1);
  }
  Serial.println("Found VCNL4010");
  
}

void loop() {
  Serial.print("Ambient: "); Serial.println(vcnl.readAmbient());
  Serial.print("Proximity: "); Serial.println(vcnl.readProximity());
  int prox = vcnl.readProximity();
  int val = prox/2000;
 
  for (pos = 0; pos <= 100; pos += val) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 100; pos >= 0; pos -= val) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
