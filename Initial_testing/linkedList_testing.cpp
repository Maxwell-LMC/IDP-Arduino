#include <iostream>

using namespace std;

enum board_nodes {START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE};
board_names bn;

class Node {
public:
	board_nodes name = START_SQUARE;
	int previous = NULL;
	int next = NULL;
};


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


class linkedList {
public:
	Node list[10];
	int current = 0;

	linkedList() {
		for (int i = 0; i < 10; i++) {
			list[i].name = board_nodes[i];
			if (i == 0) {
				list[i].previous = 9;
			}
			else {
				list[i].previous = i - 1;
			}
			if (i == 9) {
				list[i].next = 0;
			}
			else {
				list[i].next = i + 1;
			}
		}
	}

	Node next_node() {
		current = list[current].next;
		return list[current];
	}

	Node previous_node() {
		current = list[current].previous;
		return list[current];
	}
};


int main() {
	linkedList map;
	for (int i = 0; i < 30; i++) {
		cout << map.next_node().data << endl;
		nodeFunctions(map.current)
	}

	return 0;
}

