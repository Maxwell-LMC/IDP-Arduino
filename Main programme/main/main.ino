#include "header.h"


int start_button = 13;



void setup() {
	Serial.begin(9600);
}

void loop() {
	// put your main code here, to run repeatedly:
	// will start the program when the button is pressed
	while (analogRead(start_button) == 0) {};
	Serial.println("Button Pressed");

  

}
