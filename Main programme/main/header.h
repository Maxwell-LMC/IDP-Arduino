#ifndef HEADER_H
#define HEADER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <ezButton.h>
#include <Chrono.h>

#define lineLpin 5
#define lineRpin 3
#define lineLLpin 4
#define lineRRpin 2
#define ultrasonic_echopin 9
#define ultrasonic_trigpin 8
#define motionLEDpin 6
#define feedbackPin A0
#define topIRpin A3
#define greenLEDpin 12
#define redLEDpin 13
#define servo_open 0
#define servo_close 180
#define topIRthres 30
#define lower_threshold 7
#define higher_threshold 8
#define board_length 7
#define threshold_coarse 0
#define threshold_dense 5
#define IRcount 7
#define IRLEDpin 6

// sensor variables
extern int lineLLvalue, lineLvalue, lineRvalue, lineRRvalue;
extern int orientation, previous_orientation;
extern int LEDstate;

extern int droppedOffBlocks;

//motor, servo and button variables
extern Adafruit_MotorShield AFMS;
extern Servo servo;
extern ezButton toggleSwitch;
extern Adafruit_DCMotor* LeftMotor;
extern Adafruit_DCMotor* RightMotor;

// timers
extern Chrono timer;
extern Chrono start_timer;

// board node information
enum board_nodes { START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };
const board_nodes board_nodes_list[] = { START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };
const int board_nodes_time_to_start[] = { 5, 15, 20, 25, 30, 25, 15 };

// goal and direction varviables
extern int GOAL;
enum DIRECTION { CLOCKWISE = +1, ANTI_CLOCKWISE = -1 };
extern DIRECTION CURRENT_DIRECTION;

// start function variables
extern bool found_line;
extern bool at_line;

// Node class
class Node {
public:
	board_nodes name = START_SQUARE;
	int previous = NULL;
	int next = NULL;
	int time_to_start = 30;
};

// linked list class
class linkedList {
private:
	Node next_node();
	Node previous_node();
public:
	Node list[board_length];
	int length = board_length;
	int current = 0;

	linkedList();

	Node current_node();
	int current_node_show_directional_next();
	void node_function();
	void next_node_function_run();
	Node get_next_node();
};

// node functions
void nodeFunctions(int node);

// functions for getting to the line
void getToLine();
void toLine();
void toLineTurn();

class pickupOrderGenerator {
private:
	int order_list[5]{ PICKUP2, PICKUP3, PICKUP1, START_SQUARE };
	int current = 0;
public:
	void next_goal();
	int goal_zero();
};

// object definitions
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
int topIRBlocked();
int frontIRBlocked();
float UltrasonicDistance();
void tunnel();

// start functions
void startRoutine();
void getToLine();

// switch functions
bool switch_pushed();

// servo functions
void diff_block();
void grab();
void drop();

// node functions
void pickup1or3();
void pickup2();
void dropoffRedOrGreen();


#endif