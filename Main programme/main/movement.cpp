#include "header.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(2);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(1);

void stopMotors(){
	LeftMotor->setSpeed(0);
	RightMotor->setSpeed(0);
	LeftMotor->run(RELEASE);
	RightMotor->run(RELEASE);
}


void forward(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void backward(){
  LeftMotor->setSpeed(150);
  RightMotor->setSpeed(150);
  LeftMotor->run(BACKWARD);
  RightMotor->run(BACKWARD);
}


void rightAdjust(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(BACKWARD);
  
}

void leftAdjust(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(BACKWARD);
  RightMotor->run(FORWARD);

}

void halt(){
	stopMotors();
}

