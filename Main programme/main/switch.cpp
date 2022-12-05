#include "header.h"

// create ezButton object
ezButton toggleSwitch(7);
int switch_state;

// Checks if the switch has been pushed
bool switch_pushed() {
	toggleSwitch.loop(); // MUST call the loop() function first
	switch_state = toggleSwitch.getState();
	if (switch_state == HIGH) return false;
	else return true;
}
