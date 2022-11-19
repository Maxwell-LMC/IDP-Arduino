#include "header.h"


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
            Serial.println("Straight");
            forward();
            break;

        case 4:
            // too far right 0100
        case 8:
            // way too far right 1000

            // action for case 4 and 8
            Serial.println("Too far right");
            leftAdjust();
            break;

        case 2:
            // too far left 0010
        case 1:
            // way too far left 0001

            // action for case 1 and 2
            Serial.println("Too far left");
            rightAdjust();
            break;

        case 15:
            //cross 1111
            // way to make sure the robot position is correct
            board.current = PICKUP2;
        case 12:
            //left branch 1100
        case 3:
            //right branch 0011
            board.next_node_function_run();
            Serial.println(GOAL);
            Serial.println(board.current);
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
