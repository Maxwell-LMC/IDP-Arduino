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

void lineSensorsRead() {
	// module to read from line sensors
	lineLvalue = digitalRead(lineLpin);
	lineFvalue = digitalRead(lineFpin);
	lineRvalue = digitalRead(lineRpin);
	lineBvalue = digitalRead(lineBpin);
}

bool onLine(int value) {
	// module to say if the sensor is on the line
	if (value == 1) {
		return true;
	};
	return false;
}

int lineInformation(bool onLineL, bool onLineF, bool onLineR, bool onLineB) {
	// module to tell the relative position to the line
	if (onLineF) {
		if (onLineL || onLineR) {
			if (onLineL && onLineR) {
				// the robot is at a crossing
			}
			else {
				if (onLineR) {
					// the robot is at a right branch
				}
				else {
					// the robot is at a left branch
				}
			}
		}
		else {
			// the robot is straight
		}

	} else {
		if (onLineB) {
			if (onLineR) {
				// the robot is too far right
			}
			else {
				if (onLineL) {
					// the robot is too far left
				}
				else {
					// needs to go further forward
				}
			}
		}
		else {
			// begin to do tunnel process
		}
	}
	return 0;
}