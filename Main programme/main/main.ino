#include "header.h"


// int start_button = 13;
// bool pressed = false;

linkedList board;
int GOAL = START_SQUARE;
DIRECTION CURRENT_DIRECTION = ANTI_CLOCKWISE;
pickupOrderGenerator pickupOrder;
bool done = false;

Chrono timer(Chrono::SECONDS);

void setup() {
	Serial.begin(9600);
	AFMS.begin();
	servo.attach(10);
	ezButton(7);
	toggleSwitch.setDebounceTime(50);
	pinMode(ultrasonic_trigpin, OUTPUT);
	pinMode(ultrasonic_echopin, INPUT);
	toggleSwitch.setDebounceTime(50);
	pinMode(greenLEDpin, OUTPUT);
	pinMode(redLEDpin, OUTPUT);
}

void robotMain() {
	servo.write(servo_open);
	delay(200);
	GOAL = pickupOrder.goal_zero();
	CURRENT_DIRECTION = ANTI_CLOCKWISE;
	startRoutine();
	while (!done) {
		lineSensorsRead();
		getOrientation();
		lineFollowing();
	}
}

void loop() {
	// put your main code here, to run repeatedly:
	while (!switch_pushed()) {}
	Serial.println("START");
	robotMain();
}
