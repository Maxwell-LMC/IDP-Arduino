#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Servo servo;
int feedbackPin = A0;
float vol, avg, sum;
float threshold_coarse = 7;
float threshold_dense = 25;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
}

void loop() {
  servo.write(0); //relaxed position
  delay(3000);
  servo.write(120); //grabbed position
  delay(5000);
  sum = 0;
  for(int i = 1; i <= 50; i++){
    vol = analogRead(feedbackPin);
    sum += vol;
    Serial.print("Average: ");
    Serial.print(sum / i);
    Serial.print(" Instant: ");
    Serial.print(vol);
    Serial.print("\n");
    delay(100);
  }
  if((sum/50)> threshold_dense){
      Serial.println("Result: Dense");
  }
  else if((sum /50 )> threshold_coarse){
      Serial.println("Result: Coarse");
  }
  else{
      Serial.println("No block detected");
  }
}
