#include "header.h"

void nodeFunctions(int node) {
	switch (node) {
	case START_SQUARE:
		Serial.println("start square");
		if (CURRENT_DIRECTION == CLOCKWISE) {
			left90();
		}
		else {
			right90();
		}
		forward();
		delay(500);
		halt();
		done = true;
		break;
	case GREEN_SQUARE:
		Serial.println("green square");
		dropoffRedOrGreen();
		break;
	/*case TUNNEL:
		Serial.println("tunnel");
		break;*/
	case PICKUP1:
		Serial.println("pick up 1");
		pickup1or3();
		break;
	case PICKUP2:
		Serial.println("pick up 2");
		grab();
		break;
	case PICKUP3:
		Serial.println("pick up 3");
		pickup1or3();
		break;
	case RED_SQUARE:
		Serial.println("red square");
		dropoffRedOrGreen();
		break;
	}
}

void pickup1or3() {
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		left90();
	}
	forward();
	delay(500);
	halt();
	grab();
	uTurn();
	directionToGoal();
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		left90();
	}
}

void dropoffRedOrGreen() {
	if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
	else {
		right90();
	}
	forward();
	delay(500);
	halt();
	drop();
	backward();
	delay(100);
	uTurn();
	directionToGoal();
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		left90();
	}
	getToLine();
}