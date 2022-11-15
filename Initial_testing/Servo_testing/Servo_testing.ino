#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Servo servo;
int feedbackPin = A0;
float vol;
float start_millis;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
  
}

void loop() {
  servo.write(100);
  vol = analogRead(feedbackPin);
  Serial.println(vol);
  delay(2000);
  start_millis = millis();
  servo.write(150);
  while(servo.read() < 149){
    Serial.println(servo.read());
  }
  Serial.print("time taken: ");
  Serial.print(millis() - start_millis);
  Serial.println(" ");
  vol = analogRead(feedbackPin);
  Serial.println(vol);
  delay(2000);
  
}
