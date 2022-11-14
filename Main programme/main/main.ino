#include "header.h"


// int start_button = 13;
// bool pressed = false;

void setup() {
	Serial.begin(9600);
	AFMS.begin();
}

void loop() {
	// put your main code here, to run repeatedly:
	while (true) { 
		lineFollowing();
		Serial.println(orientation);
	}
}
