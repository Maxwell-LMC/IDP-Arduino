#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Servo servo;
int feedbackPin = A0;
float vol;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
  
}

void loop() {
  servo.write(270);
  vol = analogRead(feedbackPin);
  Serial.println(vol);
  delay(2000);
  servo.write(0);
  vol = analogRead(feedbackPin);
  Serial.println(vol);
  delay(2000);
  
}
