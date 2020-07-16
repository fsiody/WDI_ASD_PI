// pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int w;
	node *next;
};

int main()
{
	node *first, *p;
	first = NULL;
	int a = 1;

	for (int i = 10; i > 0; i--) {
		p = new node;
		p->w = 100 - a; a += 8;
		p->next = first;
		first = p;
	}

	cout << first->w << endl;
	cout << first->next->w << endl;

	node *r = first;
	cout << r->w << endl;

	*r = *first;
	cout << first << endl;
	cout << r ->next->w<< endl;

	r = NULL;
	r = r->next;
	cout << r;

    return 0;
}

