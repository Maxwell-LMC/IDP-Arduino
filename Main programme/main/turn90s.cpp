#include "header.h"

void right90() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(BACKWARD);
	RightMotor->run(FORWARD);
	lineSensorsRead();
	getOrientation();
	int orientations[3] = {8, 4, 0};
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
	int orientations[3] = {1, 2, 0};
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