#include "header.h"


int start_button = 13;

void lineFollowing() {
	while (true) {

		getLineInformation();

		switch (orientation) {
		default:
			Serial.println("Unknown");
			break;
		case 1:
			// the robot is at a crossing
			Serial.printLn("Crossing");
			break;
		case 2:
			// the robot is at a right branch
			Serial.printLn("Right Branch");
			break;
		case 3:
			// the robot is at a left branch
			Serial.printLn("Left Branch");
			break;
		case 4:
			// the robot is straight
			Serial.printLn("Straight");
			forward();
			break;
		case 5:
			// robot is too far right
			Serial.printLn("Too Far Right");
			leftAdjust();
			break;
		case 6:
			// robot is too far left
			Serial.printLn("Too Far Left");
			rightAdjust();
			break;
		case 7:
			// the robot needs to go further forwards
			Serial.printLn("Needs to go further forwards");
			forward();
			break;
		case 8:
			// the robot needs to begin the tunnel process
			Serial.printLn("Tunnel");
			break;
		}
	}
}


void setup() {
	Serial.begin(9600);
}

void loop() {
	// put your main code here, to run repeatedly:
	
	// will start the program when the button is pressed
	while (analogRead(start_button) == 0) {};
	Serial.println("Button Pressed");

  

}
