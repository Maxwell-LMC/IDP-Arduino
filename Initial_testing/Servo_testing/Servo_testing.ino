#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Servo servo;
int feedbackPin = A0;
float vol, sum, avg;
float threshold_coarse = 50;
float threshold_dense = 100;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
}

void loop() {
  servo.write(100); //relaxed position
  delay(3000);
  servo.write(150); //grabbed position
  delay(1000);
  for(int i = 1; i <= 20; i++){
    vol = analogRead(feedbackPin);
    sum += vol;
    Serial.print("Average: ");
    Serial.print(sum / i);
    Serial.print(" Instant: ");
    Serial.print(vol);
    Serial.print("\n");
    delay(250);
  }
  if((sum/20)> threshold_dense){
      Serial.println("Result: Dense");
  }
  else if(sum > threshold_coarse){
      Serial.println("Result: Coarse");
  }
  else{
      Serial.println("No block detected");
  }
}
