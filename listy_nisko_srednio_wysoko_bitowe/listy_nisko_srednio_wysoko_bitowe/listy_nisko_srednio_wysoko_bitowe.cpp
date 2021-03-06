// listy_nisko_srednio_wysoko_bitowe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int v;
	node *next;
};

int bit(int x) {
	int wynik = 0;
	while (x) {
		wynik += x % 2; x /= 2;
	}
	return wynik;
}

void add_at_b(node *&first, node *&p) {
	p->next = first;
	first = p;
}

void zadanie(node *&first) {
	node *f1, *f2, *f3, *p;
	f1 = f2 = f3 = p = NULL;
	int b = 0;
	while (first) {
		p = first;
		first = first->next;
		b = bit(p->v);
		if (b < 5) add_at_b(f1, p);
		if (b >=5 && b <= 7) add_at_b(f2, p);
		if (b > 7) add_at_b(f3, p);
	}
	while (f3) {
		p = f3;
		f3 = f3->next;
		add_at_b(first, p);
	}
	while (f2) {
		p = f2,
		f2 = f2->next;
		add_at_b(first,p);
	}
	while (f1) {
		p = f1;
		f1 = f1->next;
		add_at_b(first, p);
	}
}



int main()
{
	node *first, *p;
	first = p = NULL;
	int a = 50;
	for (int i = 0; i < 15; i++) {
		p = new node;
		p->v = rand();
		p->next = first;
		first = p;
	}
	while (p) {
		cout << p->v << " -- " << bit(p->v) << endl;
		p = p->next;
	}
	cout << endl << endl;
	zadanie(first);
	p = first;
	while (p) {
		cout << p->v << " -- " << bit(p->v) << endl;
		p = p->next;
	}
	cout << endl << endl;

    return 0;
}

