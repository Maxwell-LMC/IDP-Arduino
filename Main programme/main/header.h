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
extern int orientation[4];
extern int previous_orientation[4];

extern Adafruit_MotorShield AFMS;


//movement functions
void forward();
void backward();
void right90();
void left90();
void uTurn();
void rightAdjust();
void leftAdjust();

//sensor functions
void lineFollowing();
void lineSensorsRead();

//higher-level modules
void navigateToBlock();
void grab();
void backToBase();

//utils
bool compare_array(int a[4], int b[4]);

#endif