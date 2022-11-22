#include "header.h"

int tunnel_state = 0; //0 is straight, 1 is too close, 2 is too far
int previous_tunnel_state = 100;

void lineFollowing() {
	if (orientation != previous_orientation) {
		previous_orientation = orientation;
		switch (orientation) {
		default:
			Serial.println("Not a recognised orientation");
			Serial.println(orientation);
			break;
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
			board.next_node_function_run();
			if (timer.hasPassed(3000)) {
				board.next_node_function_run();
				Serial.println(GOAL);
				Serial.println(board.current);
				timer.restart();
			}
			break;
		case 16:
			//tunnel
			board.next_node_function_run();
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
}

void tunnel() {
	while (topIRBlocked()) {
		float distance = UltrasonicDistance();

		if (lower_threshold < distance < higher_threshold) {
			tunnel_state = 0;
		}
		else if (distance < lower_threshold) {
			tunnel_state = 1;
		}
		else if (distance > higher_threshold) {
			tunnel_state = 2;
		}
		if (tunnel_state != previous_tunnel_state) {
			previous_tunnel_state = tunnel_state;
			if (tunnel_state == 0) {
				forward();
			}
			else if (tunnel_state == 1) {
				leftAdjust();
			}
			else if (tunnel_state == 2) {
				rightAdjust();
			}
		}
	}
}