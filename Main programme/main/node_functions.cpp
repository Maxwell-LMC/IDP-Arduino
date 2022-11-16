#include "header.h"

void nodeFunctions(board_nodes node) {
	switch (node) {
	case START_SQUARE:
		cout << "start square" << endl;
		break;
	case GREEN_SQUARE:
		cout << "green square" << endl;
		break;
	case TUNNEL:
		cout << "tunnel" << endl;
		break;
	case PICKUP1:
		cout << "pick up 1" << endl;
		break;
	case PICKUP2:
		cout << "pick up 2" << endl;
		break;
	case PICKUP3:
		cout << "pick up 3" << endl;
		break;
	case RED_SQUARE:
		cout << "red square" << endl;
		break;
	}
}