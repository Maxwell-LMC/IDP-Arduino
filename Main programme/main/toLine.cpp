#include "header.h"

// Turns right until the robot is straight on the line
void right90() {
	// turns right
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(BACKWARD);
	RightMotor->run(FORWARD);
	// keeps turning until the robot has passed through the expected orientations
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

// Turns left until the robot is straight on the line
void left90() {
	// turns left
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(FORWARD);
	RightMotor->run(BACKWARD);
	// keeps turning until the robot has passed through the expected orientations
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

// Does a u-turn with no line present (turns for a set amount of time)
void uTurn() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(FORWARD);
	RightMotor->run(BACKWARD);
	delay(3000);
	halt();
	digitalWrite(motionLEDpin, HIGH);
}

// Uses getToLine() to reach the main line from already being on the line
void toLine() {
	found_line = true;
	at_line = false;
	forward();
	while (!at_line) {
		lineSensorsRead();
		getOrientation();
		getToLine();
	}
}

// Turns the correct way depending on which way the target direction is
void toLineTurn() {
	toLine();
	if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
		right90();
	}
	else if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
}