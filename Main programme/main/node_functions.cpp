#include "header.h"

// Updates GOAL to the next goal in the list
void pickupOrderGenerator::next_goal() {
	GOAL = order_list[++current];
}

// Returns the first goal
int pickupOrderGenerator::goal_zero() {
	return order_list[0];
}


// Turns off the line, picks up and differentiates the blocks before returning to the line
void pickup1or3() {
	// turns onto the branch
	forward();
	delay(650);
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		left90();
	}
	// moves to the block
	forward();
	delay(500);
	halt();
	// differentiates the block
	grab();
	digitalWrite(motionLEDpin, HIGH);
	backward();
	delay(1000);
	// works out direction to next goal
	directionToGoal();
	// turns off the branch
	if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
	else {
		right90();
	}
}


// Picks up and differentiates the blocks
void pickup2() {
	forward();
	halt();
	// differentitates the block
	grab();
	digitalWrite(motionLEDpin, HIGH);
	// works out the direction to the goal and turns to that direction
	directionToGoal();
	if (CURRENT_DIRECTION == CLOCKWISE) {
		right90();
	}
	else {
		forward();
	}
}

// Turns into the square, drops off the block and returns to the line
void dropoffRedOrGreen() {
	// turns off the main line
	forward();
	delay(670);
	if (CURRENT_DIRECTION == CLOCKWISE) {
		left90();
	}
	else {
		right90();
	}
	// goes to the edge of the square
	toLine();
	// adjusts direction and moves forward
	leftAdjust();
	delay(100);
	rightAdjust();
	delay(50 * droppedOffBlocks++);
	forward();
	delay(400);
	halt();
	// drops of the block and turns around
	drop();
	digitalWrite(motionLEDpin, HIGH);
	backward();
	delay(100);
	uTurn();
	// leaves the block in the direction of the next goal
	digitalWrite(motionLEDpin, HIGH);
	pickupOrder.next_goal();
	directionToGoal();
	toLineTurn();
}


// Runs the correct function for the node that the robot is at
void nodeFunctions(int node) {
	switch (node) {
	case START_SQUARE:
		// turns into the square and stops there
		Serial.println("start square");
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
		while (true) {};
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
