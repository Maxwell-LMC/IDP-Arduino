#include "header.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(2);
Servo myservo;

void forward(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void backward(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);
}

void right90(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(3000);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void left90(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);
  delay(3000);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void uTurn(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  delay(6000);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void rightAdjust(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(200);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void leftAdjust(){
  LeftMotor->setSpeed(200);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);

}