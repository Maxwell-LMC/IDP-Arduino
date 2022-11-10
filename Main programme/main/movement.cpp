#include "header.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(2);
Servo myservo;

void forward(){
  LeftMotor->setSpeed(255);
  RightMotor->SetSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void backward(){
  LeftMotor->setSpeed(255);
  RightMotor->SetSpeed(255);
  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);
}

void right90(){
  //need testing
}

void left90(){
  //need testing
}

void uTurn(){
  //need testing
}

void rightAdjust(){
  LeftMotor->setSpeed(255);
  RightMotor->SetSpeed(200);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void leftAdjust(){
  LeftMotor->setSpeed(200);
  RightMotor->SetSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);

}