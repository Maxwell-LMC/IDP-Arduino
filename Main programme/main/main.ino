#include "header.h"


// int start_button = 13;
// bool pressed = false;

linkedList board;
int GOAL = START_SQUARE;
DIRECTION CURRENT_DIRECTION = ANTI_CLOCKWISE;
pickupOrderGenerator pickupOrder;
bool done = false;

void setup() {
	Serial.begin(9600);
	AFMS.begin();
	servo.attach(10);
	ezButton(7);
	toggleSwitch.setDebounceTime(50); 
  pinMode(ultrasonic_trigpin, OUTPUT);
  pinMode(ultrasonic_echopin, INPUT);
}

void robotMain(){
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
	while(!switch_pushed()){}
	Serial.println("START");
	robotMain();
}
