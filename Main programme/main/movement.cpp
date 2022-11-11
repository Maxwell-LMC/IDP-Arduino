#include "header.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *LeftMotor = AFMS.getMotor(2);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(1);
Servo myservo;

int tooRight[4] = {0,0,0,1};
int tooLeft[4] = {0,0,1,0};
int straight[4] = {1,1,0,0};
int stray[4] = {0,0,0,0};


void forward(){
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
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
  LeftMotor->setSpeed(255);
  RightMotor->setSpeed(100);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
}

void leftAdjust(){
  LeftMotor->setSpeed(100);
  RightMotor->setSpeed(255);
  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);

}

void halt(){
  LeftMotor->setSpeed(0);
  RightMotor->setSpeed(0);
  LeftMotor->run(RELEASE);
  RightMotor->run(RELEASE);
}

void lineFollowing() {
  if(compare_array(orientation, straight)){
    forward();
  }
  else if(compare_array(orientation, tooRight)){
    leftAdjust();
  }
  else if(compare_array(orientation, tooLeft)){
    rightAdjust();
  }
  else if(compare_array(orientation, stray)){
  }
}