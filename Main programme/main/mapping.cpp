#include "header.h"

class Node {
public:
	int name = NULL;
	int previous = NULL;
	int next = NULL;
};

enum board_nodes {START_SQUARE, GREEN_SQUARE, TUNNEL, PICKUP1, PICKUP2, PICKUP3, RED_SQUARE};


class linkedList {
public:
	Node list[7];
	int current = 0;

	linkedList() {
		board_nodes bn;
		for (int i = 0; i < 7; i++) {
			list[i].name = i;
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

