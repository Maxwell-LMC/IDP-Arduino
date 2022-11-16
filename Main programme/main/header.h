#ifndef header
#define header

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
using namespace std;

extern int lineLLpin, lineLpin, lineRpin, lineRRpin;
extern int lineLLvalue, lineLvalue, lineRvalue, lineRRvalue;
extern int orientation, previous_orientation;
// extern enum board_nodes;

extern Adafruit_MotorShield AFMS;


//movement functions
void forward();
void backward();
void right90();
void left90();
void uTurn();
void rightAdjust();
void leftAdjust();
void halt();

//sensor functions
void lineFollowing();
void lineSensorsRead();
void getOrientation();

//higher-level modules
void grab();

//utils


#endif