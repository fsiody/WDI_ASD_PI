// lancuch_odwrocic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int w;
	node *next;
};
const int n = 10;


void reverse(node * first) {
	node *p1, *fa, *pa;
	fa = new node;
	fa= NULL;
//	p1 = new node;
	p1 = first;
	while (p1 != NULL) {
		pa = new node;
		*pa = *p1;
		pa->next = fa;
		fa = pa;
		p1 = p1->next;
		                                 
	}
//	return fa;
	first = fa; 
	while (fa != NULL) {
		cout << fa->w << "  ";
		fa = fa->next;
	}
	cout << endl;
}

int main()
{
	node* first; node* p; // обьявляем first и p, указатели типа node
	first = NULL;
	for (int i = 0; i < n; i++) {p = new node;	p->w = rand() % 99;	p->next = first;first = p;	}
	p = first;
	while (p != NULL) {	cout << p->w << "  ";	p = p->next;	} cout << endl;

	reverse(first);
	p = first;
	while (p != NULL) { cout << p->w << "  "; p = p->next; }	cout << endl;

    return 0;
}

