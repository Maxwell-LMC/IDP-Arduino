#ifndef header
#define header

#include <Arduino.h>
#include <string.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
using namespace std;

extern int lineFpin, lineLpin, lineRpin, lineBpin;
extern int lineLvalue, lineFvalue, lineRvalue, lineBvalue;
extern string orientation, string previous_orientation;

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

//higher-level modules
void navigateToBlock();
void grab();
void backToBase();

//utils


#endif