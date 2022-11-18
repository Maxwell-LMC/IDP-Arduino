#include "header.h"

bool found_line = false;
bool at_line = false;

void getToLine() {
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
        case 12:
            // semi way too far right 1100

            // action for case 4, 8 and 12
            Serial.println("Too far right");
            leftAdjust();
            break;

        case 2:
            // too far left 0010
        case 1:
            // way too far left 0001
        case 3:
            // semi way too far right 0011

            // action for case 1, 2 and 3
            Serial.println("Too far left");
            rightAdjust();
            break;

        case 15:
            // found line 1111
            if (found_line) {
                at_line = true;
            }
            found_line = true;
            break;
        }
    }
}

void startRoutine() {
    found_line = false;
    at_line = false;
	while (!at_line) {
		lineSensorsRead();
		getOrientation();
		getToLine();
	}
    if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
        // turn right
        right90();
    }
    else if (CURRENT_DIRECTION == CLOCKWISE) {
        // turn left
        left90();
    }

}