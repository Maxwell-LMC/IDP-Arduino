#include "header.h"


// int start_button = 13;
// bool pressed = false;

linkedList board;
int GOAL = START_SQUARE;

void setup() {
	Serial.begin(9600);
	AFMS.begin();
}

void loop() {
	// put your main code here, to run repeatedly:
	GOAL = PICKUP2;
	while (true) {
		lineSensorsRead();
		getOrientation(); 
		lineFollowing();
	}
}
