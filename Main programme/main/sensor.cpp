#include "header.h"

int lineLpin = 2;
int lineFpin = 3;
int lineRpin = 4;
int lineBpin = 5;

int lineLvalue = 0;
int lineFvalue = 0;
int lineRvalue = 0;
int lineBvalue = 0;

string orientation = "0000";
string previous_orientation = "0000";

void lineSensorsRead() {
	// module to read from line sensors
	lineLvalue = digitalRead(lineFpin);
	lineFvalue = digitalRead(lineBpin);
	lineRvalue = digitalRead(lineRpin);
	lineBvalue = digitalRead(lineLpin);
}

string onLine(int value) {
	if (value == 1) {
		return "1";
	}
	else {
		return "0";
	}
}

void getOrientation() {
	lineSensorsRead();
	orientation = onLine(lineLvalue) + onLine(lineFvalue) + onLine(lineRvalue) + onLine(lineBvalue);
}