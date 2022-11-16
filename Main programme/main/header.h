#ifndef header
#define header

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
using namespace std;

extern int lineLLpin, lineLpin, lineRpin, lineRRpin;
extern int lineLLvalue, lineLvalue, lineRvalue, lineRRvalue;
extern int orientation, previous_orientation;


extern Adafruit_MotorShield AFMS;

enum board_nodes { START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };
const board_nodes board_nodes_list[] = { START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };

// linked list classes
class Node {
public:
	board_nodes name = START_SQUARE;
	int previous = NULL;
	int next = NULL;
};

class linkedList {
public:
	Node list[7];
	int length = 7;
	int current = 0;

	linkedList();

	Node next_node();
	Node previous_node();
	Node current_node();
	void node_function();
	void next_node_function_run();
};


extern int GOAL;
linkedList board;

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

// node functions
void node_functions(int node);

void grab();

//utils


#endif