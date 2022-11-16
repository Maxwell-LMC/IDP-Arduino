#include "header.h"


void lineFollowing() {
    if (orientation != previous_orientation) {
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
        case 8:
            // too far right 1000
            Serial.println("Too far right");
            leftAdjust();
            break;
        case 4:
            // too far left 0100
            Serial.println("Too far left");
            rightAdjust();
            break;
        }
    }
}

