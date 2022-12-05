#include "header.h"

int tunnel_state = 0;
int previous_tunnel_state = 100;
float ref = 8.5;
int Kp = 25;
float error = 0;
float error_bound = 0.2;


// Checks if the robot should return to the start square and runs board.next_node_function_run()
void at_node() {
	Serial.println("**** REACHED NODE ****");
	Serial.println(board.current_node_show_directional_next());

	// compares the time left to the time required to get back to the start square
	if (start_timer.hasPassed(300 - board.list[board.current_node_show_directional_next()].time_to_start)) {
		board.get_next_node();
		GOAL = START_SQUARE;
		int previous_direction = CURRENT_DIRECTION;
		directionToGoal();
		if (previous_direction != CURRENT_DIRECTION) {
			right90();
		}
	}

	// tries to run the node function
	board.next_node_function_run();
	timer.restart();
}


// Takes in the orientation of the robot from the sensors and uses this to decide the next action for the robot
void lineFollowing() {

	if (orientation != previous_orientation) {
		previous_orientation = orientation;
		switch (orientation) {
			// the robot is straight
		case 0:
			forward();
			break;

			// the robot is too far right
		case 4:
		case 8:
			leftAdjust();
			break;

			// the robot is too far left
		case 2:
		case 1:
			rightAdjust();
			break;

			// the robot could be at a node
		case 15:
		case 12:
		case 3:
		case 16:
		default:
			// checks that the value is not node to an error when the sensors hit the ramp
			if ((board.current_node().name == RED_SQUARE && board.current_node_show_directional_next() == PICKUP3) ||
				(board.current_node().name == PICKUP3 && board.current_node_show_directional_next() == RED_SQUARE)) {
				if (timer.hasPassed(10)) {
					Serial.println("PASSED RAMP");
					at_node();
				}
			}
			// checks it is not due to having hit the same node without moving off it
			else if (timer.hasPassed(2)) {
				at_node();
			}
			else {
				forward();
				delay(120);
			}
			break;
		}
	}
}


// Works out if the robot should traverse the board anticlockwise or clockwise depending on the current position and the position of the goal
void directionToGoal() {
	if (GOAL == START_SQUARE) {
		if (board.current > board.length / 2) {
			CURRENT_DIRECTION = CLOCKWISE;
		}
		else {
			CURRENT_DIRECTION = ANTI_CLOCKWISE;
		}
	}
	else if (GOAL < board.current) {
		CURRENT_DIRECTION = ANTI_CLOCKWISE;
	}
	else {
		CURRENT_DIRECTION = CLOCKWISE;
	}
	// makes the robot go through the tunnel and the ramp on the first loop
	if (droppedOffBlocks == 0) {
		CURRENT_DIRECTION = ANTI_CLOCKWISE;
	}
}


// Using proportional control to allow the robot to pass through the tunnel
void tunnel() {
	forward();
	delay(500);
	Serial.println("RUNNING TUNNEL");
	int topIRBlockedCount = 0;
	while (topIRBlockedCount <= 3) {
		if (topIRBlocked() != 1) {
			topIRBlockedCount++;
		}
		float distance = UltrasonicDistance();
		error = distance - ref;
		if (error < -error_bound) {
			LeftMotor->setSpeed(255);
			RightMotor->setSpeed(255 - Kp * error);
			LeftMotor->run(FORWARD);
			RightMotor->run(FORWARD);
		}
		else if (error > error_bound) {
			LeftMotor->setSpeed(255 + Kp * error);
			RightMotor->setSpeed(255);
			LeftMotor->run(FORWARD);
			RightMotor->run(FORWARD);
		}
		else {
			forward();
		}
	}
	timer.restart();
	Serial.println("TUNNEL DONE");
}