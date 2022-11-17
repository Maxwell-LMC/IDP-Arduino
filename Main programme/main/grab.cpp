#include "header.h"

Servo servo;
int feedbackPin = A0;
float vol, avg, sum;
float threshold_coarse = 7;
float threshold_dense = 30;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
}

void loop() {
  servo.write(150); //relaxed position
  delay(3000);
  servo.write(100); //grabbed position
  delay(2000);
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
  else if((sum/50)> threshold_coarse){
      Serial.println("Result: Coarse");
  }
  else{
      Serial.println("No block detected");
  }
}
