#include <iostream>

using namespace std;

enum board_nodes {START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE};
const board_nodes board_nodes_list[] = {START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE};

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
	Node list[7];
	int length = 7;
	int current = 0;

	linkedList() {
		for (int i = 0; i < length; i++) {
			list[i].name = board_nodes_list[i];
			if (i == 0) {
				list[i].previous = length;
			}
			else {
				list[i].previous = i - 1;
			}
			if (i == length-1) {
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

	Node current_node() {
		return list[current];
	}
};


int main() {
	linkedList map;
	for (int i = 0; i < 30; i++) {
		nodeFunctions(map.current_node().name);
		map.next_node();
	}

	return 0;
}

