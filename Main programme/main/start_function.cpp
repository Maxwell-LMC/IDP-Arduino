#include "header.h"

// variables for getToLine()
bool found_line = false;
bool at_line = false;


// Using a variation of line following to get from inside a sqaure to the main line
void getToLine() {
	if (orientation != previous_orientation) {
		previous_orientation = orientation;
		switch (orientation) {
			// the robot is straight
		case 0:
			Serial.println("Straight");
			forward();
			break;

			// the robot needs to turn left
		case 4:
		case 8:
		case 12:
			leftAdjust();
			break;

			// the robot needs to turn right
		case 2:
		case 1:
		case 3:
			rightAdjust();
			break;

			// the robot is at a line
		case 7:
		case 14:
		case 15:
		default:
			if (found_line) {
				at_line = true;
			}
			found_line = true;
			forward();
			delay(500);
			break;
		}
	}
}


// Uses getToLine() to reach the main line and turn the correct direction
void startRoutine() {
	// runs getToLine()
	digitalWrite(motionLEDpin, HIGH);
	found_line = false;
	at_line = false;
	forward();
	while (!at_line) {
		lineSensorsRead();
		getOrientation();
		getToLine();
	}
	// turns the relevant way depending on the desired direction
	if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
		right90();
	}
	else if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
	Serial.println("start routine done");
	timer.restart();
}