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
            Serial.println("Too far right");
            leftAdjust();
            break;
        case 2:
            // too far left 0010
            Serial.println("Too far left");
            rightAdjust();
            break;
        case 1:
            // way too far right 0001
            Serial.println("Way too far right");
            leftAdjust();
            break;
        case 8:
            // way too far left 1000
            Serial.println("Way too far left");
            rightAdjust();
            break;
        case 12:
            //left branch 1100
            board.next_node_function_run();
            break;
        case 3:
            //right branch 0011
            board.next_node_function_run();
            break;
        case 15:
            //cross 1111
            board.next_node_function_run();
            break;
        }
    }
}

