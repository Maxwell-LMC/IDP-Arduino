#ifndef HEADER_H
#define HEADER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <ezButton.h>

using namespace std;


extern int lineLLpin, lineLpin, lineRpin, lineRRpin;
extern int lineLLvalue, lineLvalue, lineRvalue, lineRRvalue;
extern int orientation, previous_orientation;

//motor initialisation
extern Adafruit_MotorShield AFMS;
extern Servo servo;
extern ezButton toggleSwitch;

enum board_nodes { START_SQUARE, GREEN_SQUARE, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };
const board_nodes board_nodes_list[] = { START_SQUARE, GREEN_SQUARE, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE };

// Node class
class Node {
public:
	board_nodes name = START_SQUARE;
	int previous = NULL;
	int next = NULL;
};

// linked list class
class linkedList {
public:
	Node list[6];
	int length = 6;
	int current = 0;

	linkedList();

	Node next_node();
	Node previous_node();
	Node current_node();
	void node_function();
	void next_node_function_run();
};


extern int GOAL;

// node functions
void nodeFunctions(int node);


extern linkedList board;


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


bool switch_pushed();

void grab();

//utils


#endif