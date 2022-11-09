#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Servo servo;


void setup() {
  servo.attach(10);
}

void loop() {
  servo.write(0);
  delay(200);
  servo.write(10);
  delay(200);
}
