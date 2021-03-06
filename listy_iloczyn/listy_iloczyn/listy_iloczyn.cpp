// listy_iloczyn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int v;
	node *next;
};


void add_at_b(node *&first, node *add) {
	node *tmp;
	tmp = new node;
	*tmp = *add;
	tmp->next = first;
	first = tmp;
}

node *iloczyn(node *first1, node *first2) {
	node *newf = NULL;
	node *tmp = NULL;
	tmp = first1;
	first1 = new node;
	first1->next = tmp;

	tmp = first2;
	first2 = new node;
	first2->next = tmp; tmp = NULL;

	while (first1->next && first2->next) {
		if (first1->next->v == first2->next->v) {
			add_at_b(newf, first1->next);
			first1 = first1->next;
			first2 = first2->next;
		}
		else {
			if (first1->next->v > first2->next->v) {
				first2 = first2->next;
			}
			else {
				first1 = first1->next;
			}
		}
	}
	return newf;
}

void get_first_last(node *&first, node *&last) {
	last = new node;
	last->next = first;
	last->v = first->v;
	while (first->v >= last->v) {
		last = first;
		first = first->next;
	}
}

node *iloczyn_cykli(node *first1, node *first2) {
	node *newf, *last1, *last2, *tmp1, *tmp2, *tmp;
	newf = NULL;
	get_first_last(first1, last1);
	get_first_last(first2, last2);
	last1->next = NULL;
	last2->next = NULL;
	tmp1 = first1; first1 = new node; first1->next = tmp1;
	tmp2 = first2; first2 = new node; first2->next = tmp2;
	while (first1->next && first2->next) {
		if (first1->next->v == first2->next->v) {
			add_at_b(newf, first1->next);
			first1 = first1->next;
			first2 = first2->next;
		}
		else {
			if (first1->next->v > first2->next->v) 	first2 = first2->next;
			else first1 = first1->next;
		}
	}
	last1->next = tmp1;
	last2->next = tmp2;
	return newf;
}

node *roznica(node *first1, node *first2) {
	node *newf = NULL;
	node *tmp = new node; tmp->next = first1; first1 = tmp;
	tmp = new node; tmp->next = first2; first2 = tmp;
	while (first1->next && first2->next) {
		if (first1->next->v == first2->next->v) {
			first1 = first1->next;
			first2 = first2->next;
		}
		else {
			if (first1->next->v > first2->next->v) {
				add_at_b(newf, first2->next);
				first2 = first2->next;
			}
			else {
				add_at_b(newf, first1->next);
				first1 = first1->next;
			}
		}
	}
	while (first1->next) {
		add_at_b(newf, first1->next);
		first1 = first1->next;
	}
	while (first2->next) {
		add_at_b(newf, first2->next);
		first2 = first2->next;
	}
	return newf;
}

node *roznica_cykli(node *first1, node *first2) {
	node *wynik = NULL;
	node *last1, *last2, *tmp, *tmp1, *tmp2;
	tmp = NULL;
	get_first_last(first1, last1);
	get_first_last(first2, last2);
	tmp1 = first1, tmp2 = first2;
	first1 = new node; first1->next = tmp1; 
	first2 = new node; first2->next = tmp2;
	last1->next = NULL; last2->next = NULL;
	while (first1->next && first2->next) {
		if (first1->next->v == first2->next->v) {
			first1 = first1->next;
			first2 = first2->next;
		}
		else {
			if (first1->next->v > first2->next->v) {
				add_at_b(wynik, first2->next);
				first2 = first2->next;
			}
			else { 
				add_at_b(wynik, first1->next);
				first1 = first1->next;
			}
		}
	}
	while (first1->next) {
		add_at_b(wynik, first1->next);
		first1 = first1->next;
	}
	while (first2->next) {
		add_at_b(wynik, first2->next);
		first2 = first2->next;
	}

	last1->next = tmp1;
	last2->next = tmp2;
	return wynik;
}

int main()
{
	node *first1, *first2, *tmp, *cykl1, *cykl2;
	first1 = first2 = tmp = NULL; cykl1 = cykl2 = NULL;
	int a[] = { 10, 9, 9, 8, 6, 6, 4, 2, 1, 11, 9, 6, 4, 2 };
	int i = 0;
	for (; i < 9; i++) {
		tmp = new node;
		tmp->v = a[i];
		tmp->next = first1;
		first1 = tmp;
		if (i == 0) cykl1 = tmp;
	}
	for (; i < 14; i++) {
		tmp = new node;
		tmp->v = a[i];
		tmp->next = first2;
		first2 = tmp;
		if (i == 9) cykl2 = tmp;
	}
	cout << "A" << endl;
	tmp = first1;
	while (tmp) {
		cout << tmp->v << " ";
		tmp = tmp->next;
	}
	cout << endl << endl;
	cout << "B" << endl;
	tmp = first2;
	while (tmp) {
		cout << tmp->v << " ";
		tmp = tmp->next;
	}
	cout << endl << endl;

	node *newf = iloczyn(first1, first2);
	cout << "iloczyn" << endl;
	while (newf) {
		cout << newf->v << " ";
		tmp = newf;
		newf = newf->next;
		delete tmp;
	}
	cout << endl;

	newf = roznica(first1, first2);
	cout << "roznica" << endl;
	while (newf) {
		cout << newf->v << " ";
		tmp = newf;
		newf = newf->next;
		delete tmp;
	}
	cout << endl;

	cykl1->next = first1;
	cykl2->next = first2;
	for (int i = 0; i < 3; i++) {
		first1 = first1->next;
		first2 = first2->next;
	}

	node *last1, *last2;
	last1 = last2 = NULL;
	newf = iloczyn_cykli(first1, first2);
	node * rozn = roznica_cykli(first1, first2);
	cout << "iloczyn cykli" << endl;
	while (newf) {
		cout << newf->v << " ";
		tmp = newf;
		newf = newf->next;
		delete tmp;
	}
	cout << endl;

	cout << "roznica cykli" << endl;
	while (rozn) {
		cout << rozn->v << " ";
		tmp = rozn;
		rozn = rozn->next;
		delete tmp;
	}
	cout << endl;


	tmp = first1->next;
	first1->next = NULL;
	first1 = tmp;
	while (first1) {
		tmp = first1;
		first1 = first1->next;
		delete tmp;
	}
	tmp = first2->next;
	first2->next = NULL;
	first2 = tmp;
	while (first2) {
		tmp = first2;
		first2 = first2->next;
		delete tmp;
	}


    return 0;
}

