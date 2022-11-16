#include "header.h"

int lineLpin = 3;
int lineRpin = 5;
int lineLLpin = 2;
int lineRRpin = 4;

int lineLvalue = 0;
int lineRvalue = 0;
int lineLLvalue = 0;
int lineRRvalue = 0;

int orientation = 0;
int previous_orientation = 0;

void lineSensorsRead() {
	// module to read from line sensors
	lineLvalue = digitalRead(lineLpin);
	lineRvalue = digitalRead(lineRpin);
	lineLLvalue = digitalRead(lineLLpin);
	lineRRvalue = digitalRead(lineRRpin);
}

void getOrientation() {
	orientation = 8*lineLLvalue + 4*lineLvalue + 2*lineRvalue + lineRRvalue;
}