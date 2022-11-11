#include "header.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(2);
Servo myservo;

void forward(){
  Serial.println("abc");
  LeftMotor->setSpeed(100);
  RightMotor->setSpeed(100);
  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);
}

void backward(){
  LeftMotor->setSpeed(50);
  RightMotor->setSpeed(50);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void right90(){
  LeftMotor->setSpeed(50);
  RightMotor->setSpeed(50);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(3000);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void left90(){
  LeftMotor->setSpeed(50);
  RightMotor->setSpeed(50);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(3000);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void uTurn(){
  LeftMotor->setSpeed(50);
  RightMotor->setSpeed(50);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(6000);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void rightAdjust(){
  LeftMotor->setSpeed(100);
  RightMotor->setSpeed(1);
  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);
}

void leftAdjust(){
  LeftMotor->setSpeed(1);
  RightMotor->setSpeed(100);
  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);

}