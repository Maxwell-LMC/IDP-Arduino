#include "header.h"


void pickupOrderGenerator::next_goal() {
	GOAL = order_list[++current];
}

int pickupOrderGenerator::goal_zero() {
	return order_list[0];
}

void pickup1or3() {
	forward();
	delay(650);
	if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
	else {
		right90();
	}
	forward();
	delay(500);
	halt();
	grab();
  digitalWrite(motionLEDpin, HIGH);
	backward();
	delay(500);
	directionToGoal();
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		left90();
	}
}

void pickup2() {
	forward();
	halt();
	grab();
  digitalWrite(motionLEDpin, HIGH);
	directionToGoal();
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		forward();
	}
}

void dropoffRedOrGreen() {
	forward();
	delay(670);
	if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
	else {
		right90();
	}
	forward();
	delay(2200);
	halt();
	drop();
  digitalWrite(motionLEDpin, HIGH);
	backward();
	delay(800);
	uTurn();
	pickupOrder.next_goal();
	directionToGoal();
	toLine();
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
	case TUNNEL:
		Serial.println("tunnel");
		tunnel();
		break;
	case PICKUP1:
		Serial.println("pick up 1");
		pickup1or3();
		break;
	case PICKUP2:
		Serial.println("pick up 2");
		pickup2();
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
