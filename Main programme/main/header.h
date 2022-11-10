#ifndef header
#define header

#include <Arduino.h>

extern int lineFpin, lineLpin, lineRpin, lineBpin;
extern int lineLvalue, lineFvalue, lineRvalue, lineBvalue;
extern int orientation;


//movement functions
void forward();
void backward();
void right90();
void left90();
void uTurn();
void rightAdjust();
void leftAdjust();

#endif