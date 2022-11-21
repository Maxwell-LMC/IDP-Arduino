#include "header.h"


void pickupOrderGenerator::next_goal() {
	GOAL = order_list[++current];
}

int pickupOrderGenerator::goal_zero() {
	return order_list[0];
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
	pickupOrder.next_goal();
	directionToGoal();
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		left90();
	}
	getToLine();
}

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
