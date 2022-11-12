#include "header.h"


void lineFollowing() {
    if (orientation != previous_orientation) {
        switch (orientation) {
        default:
            Serial.println("Not a recognised orientation");
            Serial.println(orientation)
            break;
        case "1100":
            // straight
            Serial.println("Straight");
            forward();
            break;
        case "0001":
            // too far right
            Serial.println("Too far right");
            leftAdjust();
            break;
        case "0010":
            // too far left
            Serial.println("Too far left");
            rightAdjust();
            break;
        case "1010":
            // oriented right
            Serial.println("Oriented right");
            forward();
            delay(500);
            leftAdjust();
            break;
        case "1001":
            // oriented left
            Serial.println("Oriented left");
            forward();
            delay(500);
            rightAdjust();
            break;
        }
    }
}
