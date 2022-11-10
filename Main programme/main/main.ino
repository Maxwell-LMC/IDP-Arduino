#include "header.h"


int start_button = 13;
bool pressed = false;

void lineFollowing() {
	while (true) {

		getLineInformation();

		switch (orientation) {
		default:
			Serial.println("Unknown");
			break;
		case 1:
			// the robot is at a crossing
			Serial.println("Crossing");
			break;
		case 2:
			// the robot is at a right branch
			Serial.println("Right Branch");
			break;
		case 3:
			// the robot is at a left branch
			Serial.println("Left Branch");
			break;
		case 4:
			// the robot is straight
			Serial.println("Straight");
			forward();
			break;
		case 5:
			// robot is too far right
			Serial.println("Too Far Right");
			leftAdjust();
			break;
		case 6:
			// robot is too far left
			Serial.println("Too Far Left");
			rightAdjust();
			break;
		case 7:
			// the robot needs to go further forwards
			Serial.println("Needs to go further forwards");
			forward();
			break;
		case 8:
			// the robot needs to begin the tunnel process
			Serial.println("Tunnel");
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
	while (!pressed) {
    if (analogRead(start_button) == 1){
      pressed = true;
    }
  };
	Serial.println("Button Pressed");  
  lineFollowing();
}
