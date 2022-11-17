#include "header.h"


// int start_button = 13;
// bool pressed = false;

void setup() {
	Serial.begin(9600);
	AFMS.begin();
  servo.attach(10);
  toggleSwitch.setDebounceTime(50); 
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
