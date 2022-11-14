#include "header.h"

int lineLpin = 2;
int lineFpin = 3;
int lineRpin = 4;
int lineBpin = 5;

int lineLvalue = 0;
int lineFvalue = 0;
int lineRvalue = 0;
int lineBvalue = 0;

int orientation = 0;
int previous_orientation = 0;

void lineSensorsRead() {
	// module to read from line sensors
	lineLvalue = digitalRead(lineFpin);
	lineFvalue = digitalRead(lineBpin);
	lineRvalue = digitalRead(lineRpin);
	lineBvalue = digitalRead(lineLpin);
}

int onLine(int value) {
	if (value == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void getOrientation() {
	lineSensorsRead();
	Serial.print(lineLvalue);
	Serial.print(" ");
	Serial.print(lineFvalue);
	Serial.print(" ");
	Serial.print(lineRvalue);
	Serial.print(" ");
	Serial.println(lineBvalue);
	orientation = 8*onLine(lineLvalue) + 4*onLine(lineFvalue) + 2*onLine(lineRvalue) + 1*onLine(lineBvalue);
}