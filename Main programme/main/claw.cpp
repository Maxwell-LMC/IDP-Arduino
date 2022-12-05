#include "header.h"

// differentiation variables
Servo servo;
float vol, avg, sum;

// Differentiates between the lowand high density blocksand grabs the block
void diff_block() {
	// lifts and drops the block
	servo.write(servo_open);
	delay(1000);
	servo.write(servo_close);
	delay(1000);
	servo.write(servo_open);
	delay(1000);
	// takes the servo voltage readings and averages them
	servo.write(servo_close);
	delay(3000);
	sum = 0;
	for (int i = 1; i <= 50; i++) {
		vol = analogRead(feedbackPin);
		sum += vol;
		Serial.print("Average: ");
		Serial.print(sum / i);
		Serial.print(" Instant: ");
		Serial.print(vol);
		Serial.print("\n");
		delay(100);
	}
	// works out which of the blocks it is based on the thresholds
	if ((sum / 50) > threshold_dense) {
		Serial.println("Result: Dense");
		GOAL = RED_SQUARE;
		digitalWrite(redLEDpin, HIGH);
		delay(5100);
	}
	else if ((sum / 50) > threshold_coarse) {
		Serial.println("Result: Coarse");
		GOAL = GREEN_SQUARE;
		digitalWrite(greenLEDpin, HIGH);
		delay(5100);
	}
	else {
		Serial.println("No block detected");
		GOAL = GREEN_SQUARE;
	}
}

// Runs diff_block()
void grab() {
	diff_block();
}

// Releases the block and returns the grab arms to the raised position
void drop() {
	servo.write(servo_open);
	digitalWrite(redLEDpin, LOW);
	digitalWrite(greenLEDpin, LOW);
	delay(3000);
}
