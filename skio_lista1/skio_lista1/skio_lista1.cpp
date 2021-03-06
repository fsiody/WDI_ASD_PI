// skio_lista1.cpp : Defines the entry point for the console application.
//
//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;


struct Node {
	int val;
	int height;
	struct Node** next;
};

struct SkipList {
	int max_height;
	Node* start;
	Node* end;
};

int getHeight(int max_h) {
	int h = 1;
	double p = 0.8;
	while (h < max_h && rand() / (RAND_MAX + 1.) < p) h++;
	return h;
}

Node* newNode(int val, int max_height) {
	Node* n = new Node;
	n->val = val;
	n->height = getHeight(max_height);
	n->next = new Node*[n->height];
	for (int i = 0; i < n->height; i++)n->next[i] = NULL;
	return n;
}

SkipList* newSkipList(int max_height) {
	SkipList* list = new SkipList;
		list->max_height = max_height;

		list->start = new Node;
		list->start->height = max_height;
		list->start->next = new Node*[max_height];
	
		list->end = new Node;
		list->end->height = max_height;
		list->end->next = new Node*[max_height];

	for (int i = 0; i<max_height; i++) {
		list->start->next[i] = list->end;
		list->end->next[i] = NULL;
	}

	return list;
}

void deleteNode(Node* n) {
	if(n->next) delete[]n->next;
	delete n;
}

void deleteSkipList(SkipList* list) {
	Node *tmp = list->start;
	do {
		list->start = list->start->next[0];
		tmp->next[0] = NULL;
		deleteNode(tmp);
		tmp = list->start;

	} while (list->start != list->end);
	deleteNode(tmp);
	free(list);
}

void insert(SkipList* list, Node* node) {
	Node* tmp = list->start;
	int i = list->max_height - 1;
	while (i >= 0) {
		while (tmp->next[i] != list->end && tmp->next[i]->val < node->val)
			tmp = tmp->next[i];
		if (i <= node->height) {
			node->next[i] = tmp->next[i];
			tmp->next[i] = node;
		}
		i--;
	}
}

int main(){            
	/*
	* test data:
	* Z - number of test cases
	* h, I - max height of single node (h), number of values to insert (I)
	* I values to insert
	* Output:
	* I lines, subsequent values stored in list
	*/
//	srand(time(NULL));
	int Z;
	scanf("%d", &Z);
	for (int i = 0; i<Z; i++) {
		int h, I;
		scanf("%d", &h);
		scanf("%d", &I);

		SkipList* list = newSkipList(h);
		int x;
		for (int j = 0; j<I; j++) {
			scanf("%d", &x);
			insert(list, newNode(x, h));
		}
		Node* iter = list->start; 
		while (iter->next[0] != list->end) {
			printf("%d\n", iter->next[0]->val);
			iter = iter->next[0];
		}
		deleteSkipList(list);
	}
	return 0;
}