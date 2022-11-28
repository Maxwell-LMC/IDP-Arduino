#include "header.h"

int tunnel_state = 0; //0 is straight, 1 is too close, 2 is too far
int previous_tunnel_state = 100;
float ref = 8.5;
int Kp = 25;
float error = 0;
float error_bound = 0.2;
int node_to_start_square_time = 30;

void at_node() {
	Serial.println("**** REACHED NODE ****");
	Serial.println(board.current_node_show_directional_next());

	if (start_timer.hasPassed(300 - node_to_start_square_time)) {
		GOAL = START_SQUARE;
		int previous_direction = CURRENT_DIRECTION;
		directionToGoal();
		if (previous_direction != CURRENT_DIRECTION) {
			right90();
		}
	}

	board.next_node_function_run();
	timer.restart();
}

void lineFollowing() {

	if (orientation != previous_orientation) {
		previous_orientation = orientation;
		switch (orientation) {
		/*default:
			Serial.println("Not a recognised orientation");
			Serial.println(orientation);
			break;*/

		case 0:
			// straight 0000
			forward();
			break;

		case 4:
			// too far right 0100
		case 8:
			// way too far right 1000

			// action for case 4 and 8
			leftAdjust();
			break;

		case 2:
			// too far left 0010
		case 1:
			// way too far left 0001

			// action for case 1 and 2
			rightAdjust();
			break;

		case 15:
			//cross 1111
			// way to make sure the robot position is correct
			// board.current = PICKUP2;
		case 12:
			//left branch 1100
		case 3:
			//right branch 0011
		case 16:
		default:
			// tunnel
			if ((board.current_node().name == RED_SQUARE && board.current_node_show_directional_next() == PICKUP3) ||
				(board.current_node().name == PICKUP3 && board.current_node_show_directional_next() == RED_SQUARE)) {
				if (timer.hasPassed(10)) {
					Serial.println("PASSED RAMP");
					at_node();
				}
			}
			else if (timer.hasPassed(2)) {
				at_node();
			}
			else {
				forward();
			}
			break;
		}
	}
}

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
	if (droppedOffBlocks == 0) {
		CURRENT_DIRECTION = ANTI_CLOCKWISE;
	}
	/*if (board.current_node().name == RED_SQUARE && GOAL == START_SQUARE) {
		CURRENT_DIRECTION = CLOCKWISE;
	}*/
}

void tunnel() {
	forward();
	delay(500);
	Serial.println("RUNNING TUNNEL");
	while (topIRBlocked() == 1) {
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