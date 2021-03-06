// lista_czy_petla.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int v;
	node *next;
};

bool petla(node *first) {
	node *p, *prev;
	p = new node; prev = new node;
	p = first; prev->next = first;
	while (p!=prev && p && p->next &&p->next->next) {
		prev = prev->next;
		p = p->next->next;
	}
	return p == prev;
}
 
int main()
{
	node *first, *p, *q;
	first = p = q = NULL;
	for (int i = 0; i < 0; i++) {
		p = new node;
		p->next = first;
		first = p;
		p->v = i;
		if (i == 0) q = p;
		if (i == 7) q->next = p;
	}

	p = first;
	for (int i = 0; i < 20 && p;i++) {
		cout << p->v << "  ";
		p = p->next;
	}
	cout << endl;

	if (petla(first)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
    return 0;
}

