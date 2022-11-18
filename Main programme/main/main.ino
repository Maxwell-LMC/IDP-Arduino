#include "header.h"


// int start_button = 13;
// bool pressed = false;

linkedList board;
int GOAL = START_SQUARE;
DIRECTION CURRENT_DIRECTION = ANTI_CLOCKWISE;

void setup() {
	Serial.begin(9600);
	AFMS.begin();
	servo.attach(10);
	ezButton(7);
	toggleSwitch.setDebounceTime(50); 
}

void robotMain(){
	GOAL = PICKUP2;
	CURRENT_DIRECTION = ANTI_CLOCKWISE;
	while (true) {
		lineSensorsRead();
		getOrientation(); 
		lineFollowing();
	}
}

void loop() {
	// put your main code here, to run repeatedly:
	while(!switch_pushed()){}
	robotMain();
}
