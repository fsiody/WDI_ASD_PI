// lista_insert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int v;
	node* next;
};

const int max=10;

void ins(int el, node* &f) {
	node *nowy = new node;
	nowy->v = el;	
	if (f->v >= el) {
		nowy->next = f;
		f = nowy;
	}
	else {
		node *prev, *p;
		p = f;
		prev = NULL;
		while (p != NULL && p->v < el) {
			prev = p;
			p = p->next;
		}
			prev->next = nowy;
			nowy->next = p;
	}
}


void del(int el, node* &f) {

	
	node *prev, *p;
	if (f->v == el) {
		prev = f;
		p = f->next;
		delete(prev);
		f = p;
	}
	else {
		prev = NULL;
		p = f;
		while (p->v < el) {
			prev = p;
			p = p->next;
		}
		if (p != NULL) {
			prev->next = p->next;
			delete(p);
		}
	}
}

int main()
{
	node *first, *p;
	first = NULL;
	int a = 1;
	for (int i = 0; i < max; i++) {	p = new node;p->v = 100 - a; a += 4;p->next = first;first = p;}
	
	cout << "Lancuch" << endl;
	while (p != NULL) {	cout << p->v << "  "; 	p = p->next; }	cout << endl;
	
	int in;	cout << "insert ";	cin >> in;
	ins(in, first); p = first;
	while (p != NULL) { cout << p->v << "  "; 	p = p->next; }	cout << endl;

	int d;
	cout << "delete "; cin >> d;
	del(d, first);
	p = first;
	while (p != NULL) { cout << p->v << "  "; 	p = p->next; }	cout << endl;


    return 0;
}

