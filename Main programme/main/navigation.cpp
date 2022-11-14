#include "header.h"


void lineFollowing() {
    if (orientation != previous_orientation) {
        switch (orientation) {
        default:
            Serial.println("Not a recognised orientation");
            Serial.println(orientation);
            break;
        case 12:
            // straight 1100
            Serial.println("Straight");
            forward();
            break;
        case 1:
            // too far right 0001
            Serial.println("Too far right");
            leftAdjust();
            break;
        case 2:
            // too far left 0010
            Serial.println("Too far left");
            rightAdjust();
            break;
        case 10:
            // oriented right 1010
            Serial.println("Oriented right");
            forward();
            delay(500);
            leftAdjust();
            break;
        case 9:
            // oriented left 1001
            Serial.println("Oriented left");
            forward();
            delay(500);
            rightAdjust();
            break;
        }
    }
}
