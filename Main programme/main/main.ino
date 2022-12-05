#include "header.h"

// object defintions and GOAL variables
linkedList board;
int GOAL = START_SQUARE;
DIRECTION CURRENT_DIRECTION = ANTI_CLOCKWISE;
pickupOrderGenerator pickupOrder;
int droppedOffBlocks = 0;

// timer initialisation
Chrono timer(Chrono::SECONDS);
Chrono start_timer(Chrono::SECONDS);

// Initialises all the objects which are required for buttons, servos and motors
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
	pinMode(motionLEDpin, OUTPUT);
}

// Runs the line following functions so that the robot traverses the board and compeltes the required tasks
void robotMain() {
	servo.write(servo_open);
	// sets goal and current direction
	GOAL = pickupOrder.goal_zero();
	CURRENT_DIRECTION = ANTI_CLOCKWISE;
	// runs start routine
	startRoutine();
	// runs line following
	while (true) {
		lineSensorsRead();
		getOrientation();
		lineFollowing();
	}
}


// Runs robotMain() when the button is pressed and starts the timer
void loop() {
	Serial.println("WAITING FOR BUTTON PRESS");
	// loop to hold the program until the button is pressed
	while (!switch_pushed()) {}
	start_timer.restart();
	Serial.println("START");
	robotMain();
}
