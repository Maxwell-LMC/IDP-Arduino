#include "header.h"

Servo servo;
float vol, avg, sum;
#define threshold_coarse 7
#define threshold_dense 30

void diff_block() {
	servo.write(servo_open); //relaxed position
	delay(1000);
	servo.write(servo_close); //grabbed position
	delay(1000);
	servo.write(servo_open);
	delay(1000);
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
	if ((sum / 50) > threshold_dense) {
		Serial.println("Result: Dense");
		GOAL = RED_SQUARE;
		digitalWrite(redLEDpin, HIGH);
	}
	else if ((sum / 50) > threshold_coarse) {
		Serial.println("Result: Coarse");
		GOAL = GREEN_SQUARE;
		digitalWrite(greenLEDpin, HIGH);
	}
	else {
		Serial.println("No block detected");
		GOAL = GREEN_SQUARE;
	}
}

void grab() {
	while (true) {
		if (frontIRBlocked()) {
			halt();
			diff_block();
			break;
		}
	}
}

void drop() {
	servo.write(servo_open);
	digitalWrite(redLEDpin, LOW);
	digitalWrite(greenLEDpin, LOW);
	delay(3000);
}
