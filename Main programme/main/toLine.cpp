#include "header.h"

void right90() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(BACKWARD);
	RightMotor->run(FORWARD);
	lineSensorsRead();
	getOrientation();
	int orientations[3] = { 8, 4, 0 };
	for (int i = 0; i < 3; i++) {
		while (orientation != orientations[i]) {
			lineSensorsRead();
			getOrientation();
			Serial.print(orientation);
		}
	}
	LeftMotor->run(RELEASE);
	RightMotor->run(RELEASE);
}

void left90() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(FORWARD);
	RightMotor->run(BACKWARD);
	int orientations[3] = { 1, 2, 0 };
	for (int i = 0; i < 3; i++) {
		while (orientation != orientations[i]) {
			lineSensorsRead();
			getOrientation();
			Serial.print(orientation);
		}
	}
	LeftMotor->run(RELEASE);
	RightMotor->run(RELEASE);
}

void uTurn() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(FORWARD);
	RightMotor->run(BACKWARD);
	int orientations[6] = { 1, 2, 0, 1, 2, 0 };
	for (int i = 0; i < 6; i++) {
		while (orientation != orientations[i]) {
			lineSensorsRead();
			getOrientation();
			Serial.print(orientation);
		}
	}
	LeftMotor->run(RELEASE);
	RightMotor->run(RELEASE);
}

void toLine() {
	found_line = true;
	at_line = false;
	forward();
	while (!at_line) {
		lineSensorsRead();
		getOrientation();
		getToLine();
	}
	if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
		// turn right
		right90();
	}
	else if (CURRENT_DIRECTION == CLOCKWISE) {
		// turn left
		left90();
	}
}