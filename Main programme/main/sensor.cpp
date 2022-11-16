#include "header.h"

int lineFLpin = 5;
int lineFRpin = 3;
int lineBLpin = 2;
int lineBRpin = 4;

int lineFLvalue = 0;
int lineFRvalue = 0;
int lineBLvalue = 0;
int lineBRvalue = 0;

int orientation = 0;
int previous_orientation = 0;

void lineSensorsRead() {
	// module to read from line sensors
	lineFLvalue = digitalRead(lineFLpin);
	lineFRvalue = digitalRead(lineFRpin);
	lineBLvalue = digitalRead(lineBLpin);
	lineBRvalue = digitalRead(lineBRpin);
}

void getOrientation() {
	orientation = 8*lineFLvalue + 4*lineFRvalue + 2*lineBLvalue + lineBRvalue;
}