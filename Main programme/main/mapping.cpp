#include "header.h"

// Intialises the linkedList for the board with the correct node numbers and next node and previous node values
linkedList::linkedList() {
	for (int i = 0; i < length; i++) {
		list[i].name = board_nodes_list[i];
		list[i].time_to_start = board_nodes_time_to_start[i];
		if (i == 0) {
			list[i].previous = length - 1;
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

// Updates the current node to the next node in a clockwise direction
Node linkedList::next_node() {
	current = list[current].next;
	return list[current];
}

// Updates the current node to the previous node in a clockwise direction
Node linkedList::previous_node() {
	current = list[current].previous;
	return list[current];
}

// Runs the next_node() or previous_node() depending on which way the robot is facing
Node linkedList::get_next_node() {
	if (CURRENT_DIRECTION == CLOCKWISE) {
		return next_node();
	}
	else if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
		return previous_node();
	}
}

// Returns the current node
Node linkedList::current_node() {
	return list[current];
}

// Returns the name of the next node depending on the direction the robot is facing
int linkedList::current_node_show_directional_next() {
	if (CURRENT_DIRECTION == CLOCKWISE) {
		return list[current].next;
	}
	else if (CURRENT_DIRECTION == ANTI_CLOCKWISE) {
		return list[current].previous;
	}
}

// Runs the node function for the current node
void linkedList::node_function() {
	nodeFunctions(list[current].name);
}

// Updates the current node checks if the node function should be run and then runs it 
void linkedList::next_node_function_run() {
	// updates current node
	get_next_node();
	// uses one off orientation values to overwrite the current node to prevent any errors
	if (orientation == 15) {
		current = PICKUP2;
	}
	else if (orientation == 16) {
		current = TUNNEL;
	}
	// checks if the function should be run
	if (current == GOAL) {
		node_function();
		forward();
		delay(500);
	}
	else if (current == TUNNEL) {
		node_function();
	}
	else {
		forward();
	}
}