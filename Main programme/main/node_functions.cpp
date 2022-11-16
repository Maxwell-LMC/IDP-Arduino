#include "header.h"

void nodeFunctions(board_nodes node) {
	switch (node) {
	case START_SQUARE:
		Serial.println("start square");
		break;
	case GREEN_SQUARE:
		Serial.println("green square");
		break;
	case TUNNEL:
		Serial.println("tunnel");
		break;
	case PICKUP1:
		Serial.println("pick up 1");
		break;
	case PICKUP2:
		Serial.println("pick up 2");
		break;
	case PICKUP3:
		Serial.println("pick up 3");
		break;
	case RED_SQUARE:
		Serial.println("red square");
		break;
	}
}