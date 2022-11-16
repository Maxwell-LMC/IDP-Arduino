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
        case 12:
            //left branch 1100
            break;

        case 3:
            //right branch 0011
            break;
        case 15:
            //cross
            break;
        }
    }
}

