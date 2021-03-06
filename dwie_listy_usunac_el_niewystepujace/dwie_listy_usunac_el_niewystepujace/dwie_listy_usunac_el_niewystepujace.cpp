// dwie_listy_usunac_el_niewystepujace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream";

using namespace std;

struct node {
	int w;
	node *next;
};

void delete_next(node* &p, int &wynik) {
	wynik++;
	node *tmp = p->next;
	p->next = p->next->next;
	delete(tmp);
}

int usunac(node* &f1, node* &f2) {
	node* new1 = new node; node *new2 = new node;
	new1->next = f1; new2->next = f2;
	f1 = new1; f2 = new2;
	int wynik=0;
	while (new1->next || new2->next) {
		if (new1->next == NULL) delete_next(new2,wynik);
		else {
			if (new2->next == NULL) delete_next(new1, wynik);
			else {
				if (new2->next->w > new1->next->w) delete_next(new1, wynik);
				else {
					if (new2->next->w < new1->next->w) delete_next(new2, wynik);
					else {
						new2 = new2->next;
						new1 = new1->next;
					}
				}
			}
		}
	}
	f1 = f1->next;
	f2 = f2->next;
	return wynik;
}

int main()
{
	node *first1, *first2, *p1, *p2;
	first1 = first2 = p1 = p2 = NULL;
	int a = 20;
	for (int i = 0; i < 10; i++) {
		p1 = new node;
		p1->next = first1;
		p1->w = a;
		first1 = p1;
		a -= 1+(rand() % 3);
	}
	
	a = 30;
	for (int i = 0; i < 15; i++) {
		p2 = new node;
		p2->next = first2;
		p2->w = a;
		first2 = p2;
		a -= 1+(rand() % 3);
	}
	p1 = first1; p2 = first2;
	
	cout << "A" << endl;
	while (p1) {
		cout << p1->w << "  ";
		p1 = p1->next;
	}
	cout << endl << endl;
	
	cout << "B" << endl;
	while (p2) {
		cout << p2->w << "  ";
		p2 = p2->next;
	}
	cout << endl << endl << endl;

	int n = usunac(first1, first2);
	cout << "n=" << n << endl;
	
	p1 = first1;
	p2 = first2;

	cout << "A" << endl;
	while (p1) {
		cout << p1->w << "  ";
		p1 = p1->next;
	}
	cout << endl << endl;

	cout << "B" << endl;
	while (p2) {
		cout << p2->w << "  ";
		p2 = p2->next;
	}
	cout << endl << endl << endl;


    return 0;
}

