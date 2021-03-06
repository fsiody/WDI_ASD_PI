// lancuch_cykliczny_usunac_el.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int v;
	node *next;
};

void delete_el(node *&first, int el) {
	node *p, *prev;
	prev = first;
	p = first->next;
	while (p->v != el && p != first) {
		prev = p;
		p = p->next;
	}
	if (p->v == el && p != prev) {
		if (p == first) first = first->next;
		prev->next = p->next;
		delete p;
	}
	else if (p->v == el && p) {
		delete p;
		first = NULL;
	}
}

void delete_powt(node *&first) {
	node *p, *prev, *q, *last;
	last = NULL;
	prev = first;
	p = first->next;
	q = NULL;
	while (p != first) {
		if (p->v == first->v && p != first) {
			last = first;
			while (last->next != first) last = last->next;
			while (p->v == first->v && p != first)	p = p->next;
			if (p != first) {
				q = first;
				first = p; last->next = first; prev = first;
				while (q != prev) {
					p = q->next;
					delete q;
					q = p;
				}
				p = prev->next;
			}
		}
		else {
			if (p->v == p->next->v) {
				q = p;
				while (p->v == p->next->v) p = p->next;
				prev->next = p->next;
				while (q != prev->next) {
					p = q->next;
					delete q;
					q = p;
				}
			}
			else prev = prev->next;
			p = prev->next;
		}
	}
	if(p==first && p->next!=first) {
		last = first;
		while (last->next != first) last = last->next;
		last->next = NULL;
		while (first) {
			q = first->next;
			delete first;
			first = q;
		}
	}
}


int main()
{
	node *first, *p, *q;
	first = p = NULL;
	q = NULL;
	for (int i = 0; i < 6; i++) {

		p = new node;
		cin >> p->v;
		p->next = first;
		first = p;
		if (i == 0) q = p;
	}
	q->next = first;
	do{
		cout << p->v << " ";
		p = p->next;
	} while (p && p != first);
	cout << endl;

	//int x;
//	cout << "delete ";
	//cin >> x;
	//delete_el(first, x);
	delete_powt(first);
	p = first;
	if (p) {
		do {
			cout << p->v << " ";
			p = p->next;
		} while (p && p != first);
	}
	else cout << "lancuch pusty";
	cout << endl;
    return 0;
}

