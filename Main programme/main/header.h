#ifndef header
#define header

#include <Arduino.h>

int addTwoInts(int a, int b);
int getLineInformation();

extern int lineFpin, lineLpin, lineRpin, lineBpin;
extern int lineLvalue, lineFvalue, lineRvalue, lineBvalue;
extern int orientation;

#endif