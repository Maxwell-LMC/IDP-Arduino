#include "header.h"

int lineLpin = 2;
int lineFpin = 3;
int lineRpin = 4;
int lineBpin = 5;

int orientation[4] = {0,0,0,0};
int previous_orientation[4] = {0,0,0,0};

void lineSensorsRead() {
	// module to read from line sensors and return the orientation array
	orientation[0] = digitalRead(lineFpin);
	orientation[1] = digitalRead(lineBpin);
	orientation[2] = digitalRead(lineRpin);
	orientation[3] = digitalRead(lineLpin);
}