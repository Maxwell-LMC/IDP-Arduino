#ifndef HEADER_H
#define HEADER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <ezButton.h>
#include <Chrono.h>

#define lineLpin 3
#define lineRpin 5
#define lineLLpin 2
#define lineRRpin 4
#define ultrasonic_echopin 8
#define ultrasonic_trigpin 9
#define topIRpin A1
#define frontIRpin A2
#define greenLEDpin 12
#define redLEDpin 13
#define servo_open 0
#define servo_close 100
#define servo_up 180

extern int lineLLvalue, lineLvalue, lineRvalue, lineRRvalue;
extern int orientation, previous_orientation;

//motor initialisation
extern Adafruit_MotorShield AFMS;
extern Servo servo;
extern ezButton toggleSwitch;
extern Adafruit_DCMotor* LeftMotor;
extern Adafruit_DCMotor* RightMotor;
extern Chrono timer;

enum board_nodes { START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };
const board_nodes board_nodes_list[] = { START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };


extern bool done;
extern int GOAL;
enum DIRECTION { CLOCKWISE = +1, ANTI_CLOCKWISE = -1 };
extern DIRECTION CURRENT_DIRECTION;

extern bool found_line;
extern bool at_line;

// Node class
class Node {
public:
	board_nodes name = START_SQUARE;
	int previous = NULL;
	int next = NULL;
};

// linked list class
class linkedList {
private:
	Node next_node();
	Node previous_node();
public:
	Node list[7];
	int length = 7;
	int current = 0;

	linkedList();

	Node current_node();
	void node_function();
	void next_node_function_run();
	Node get_next_node();
};

// node functions
void nodeFunctions(int node);
void getToLine();
void toLine();

class pickupOrderGenerator {
private:
	int order_list[4]{ PICKUP2, PICKUP3, PICKUP1, START_SQUARE };
	int current = 0;
public:
	void next_goal();
	int goal_zero();
};


extern linkedList board;
extern pickupOrderGenerator pickupOrder;


//movement functions
void forward();
void backward();
void right90();
void left90();
void uTurn();
void rightAdjust();
void leftAdjust();
void halt();

//sensor functions
void lineFollowing();
void lineSensorsRead();
void getOrientation();
void directionToGoal();
int topIRBlocked(float threshold);
int frontIRBlocked(float threshold);
float UltrasonicDistance();
void tunnel();
void diff_block();

void startRoutine();
void getToLine();


bool switch_pushed();

void grab();
void drop();

//utils


#endif