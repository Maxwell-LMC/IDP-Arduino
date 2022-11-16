#include "header.h"


linkedList::linkedList() {
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

Node linkedList::next_node() {
	current = list[current].next;
	return list[current];
}

Node linkedList::previous_node() {
	current = list[current].previous;
	return list[current];
}

Node linkedList::current_node() {
	return list[current];
}

void linkedList::node_function() {
	node_functions(list[current].name);
}

void linkedList::next_node_function_run() {
	next_node();
	if (current == GOAL) {
		node_function();
		delay(10000);
	}
}