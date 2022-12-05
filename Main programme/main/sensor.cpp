#include "header.h"

// sensor variables
int lineLvalue = 0;
int lineRvalue = 0;
int lineLLvalue = 0;
int lineRRvalue = 0;
int orientation = 0;
int previous_orientation = 100;
long duration;

// Takes a reading from all the line sensors
void lineSensorsRead() {
	lineLvalue = digitalRead(lineLpin);
	lineRvalue = digitalRead(lineRpin);
	lineLLvalue = digitalRead(lineLLpin);
	lineRRvalue = digitalRead(lineRRpin);
}


// Using the line and IR sensor readings to create the number of the orientation which the robot is currently at
void getOrientation() {
	orientation = 16 * topIRBlocked() + 8 * lineLLvalue + 4 * lineLvalue + 2 * lineRvalue + lineRRvalue;
	orientation = (orientation >= 16) ? 16 : orientation;
}

// Checks if there is anything covering the top IR and returns 1 if there is
int topIRBlocked() {
	float volts = analogRead(topIRpin) * 0.0048828125;
	float sum_distance = 0;
	for (int i = 0; i < IRcount; i++) {
		sum_distance += 65 * pow(volts, -1.10);
	}
	int x = (sum_distance < topIRthres* IRcount) ? 1 : 0;
	if (x == 1) {
		Serial.println("IR SENSOR BLOCKED");
	}
	return x;
}


// Measures the distance between the ultrasound reader and the wall
float UltrasonicDistance() {
	digitalWrite(ultrasonic_trigpin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
	digitalWrite(ultrasonic_trigpin, HIGH);
	delayMicroseconds(10);
	digitalWrite(ultrasonic_trigpin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(ultrasonic_echopin, HIGH);
	// Calculates the distance
	float distance = duration * 0.034 / 2;
	return distance;
}
