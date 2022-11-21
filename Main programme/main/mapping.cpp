#include "header.h"

linkedList::linkedList() {
	for (int i = 0; i < length; i++) {
		list[i].name = board_nodes_list[i];
		if (i == 0) {
			list[i].previous = length-1;
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

Node linkedList::next_node() {
	current = list[current].next;
	return list[current];
}

Node linkedList::previous_node() {
	current = list[current].previous;
	return list[current];
}

Node linkedList::get_next_node() {
	if (CURRENT_DIRECTION == CLOCKWISE) {
		return next_node();
	}
	else if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
		return previous_node();
	}
}

Node linkedList::current_node() {
	return list[current];
}

void linkedList::node_function() {
	nodeFunctions(list[current].name);  
}

void linkedList::next_node_function_run() {
	get_next_node();
	if (orientation == 15) {
		board.current == PICKUP2;
	} else if (orientation == 16) {
		board.current == TUNNEL;
	}
	if (current == GOAL) {
		node_function();
    forward();
    delay(500);
	} else {
	  forward();
    }
}