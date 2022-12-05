#include "header.h"

// intitalises the motors
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor* LeftMotor = AFMS.getMotor(2);
Adafruit_DCMotor* RightMotor = AFMS.getMotor(1);


// Stops the motors
void stopMotors() {
	LeftMotor->setSpeed(0);
	RightMotor->setSpeed(0);
	LeftMotor->run(RELEASE);
	RightMotor->run(RELEASE);
}

// Sets both motors moving forward
void forward() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(FORWARD);
	RightMotor->run(FORWARD);
}

// Sets both motors moving backwards
void backward() {
	LeftMotor->setSpeed(150);
	RightMotor->setSpeed(150);
	LeftMotor->run(BACKWARD);
	RightMotor->run(BACKWARD);
}


// Sets the right motor moving backwards and the left motor moving forwards
void rightAdjust() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(FORWARD);
	RightMotor->run(BACKWARD);

}


// Sets the left motor moving bakcwards and the right motor moving forwards
void leftAdjust() {
	LeftMotor->setSpeed(255);
	RightMotor->setSpeed(255);
	LeftMotor->run(BACKWARD);
	RightMotor->run(FORWARD);

}

// Runs stopMotors() and turns off the motionLEDpin
void halt() {
	digitalWrite(motionLEDpin, LOW);
	stopMotors();
}

