#include "header.h"


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

	linkedList() {
		for (int i = 0; i < length; i++) {
			list[i].name = board_nodes_list[i];
			if (i == 0) {
				list[i].previous = length;
			}
			else {
				list[i].previous = i - 1;
			}
			if (i == length - 1) {
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

	void node_function() {
		node_functions(list[current]);
	}

	void function_if_goal() {
		if (current == GOAL) {
			node_function();
		}
	}
};