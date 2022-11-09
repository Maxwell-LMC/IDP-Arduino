#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Servo myservo;

void setup() {
  AFMS.begin();
  myMotor1->setSpeed(250);
  myMotor1->run(FORWARD);
  myMotor2->setSpeed(250);
  myMotor2->run(FORWARD);
  myservo.attach(0)
}

void loop() {
  // put your main code here, to run repeatedly:

}
