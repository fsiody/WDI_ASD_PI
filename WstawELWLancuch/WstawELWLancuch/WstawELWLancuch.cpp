// WstawELWLancuch.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
setlocale(LC_ALL, "");


using namespace std;

struct node {
	int w;
	node *next;
};

void insert(int el, node *f) {
	node *p = NULL;
	node *r = f;
	while (r != NULL && el < r->w) { // этими штуками "ходим"
		p = r;
		r = r->next;
	}
	if (p != NULL || r != NULL || el != r->w) { // создаем то что будем вставлять
		node *x = new node;
		x->w = el;
		x->next = NULL;
		if (p == NULL && r == NULL) { // списка нет
			f = x;
			x->next = NULL;
		}
		else if (p == NULL && r != NULL) { //начало
			x->next = f;
			f = x;
		}
		else if (p != NULL && r == NULL) { //конец
			p->next = x;
		}
		else if(p!=NULL && r!=NULL && el==r->w) { //середина
			p->next = x;
			x->next = r;
		}
	}

}

void wypisz(node *f, int m) {
	node *r;
	r = f->next;
	for (int i = 0; i <m; i++) {
		cout << f->w << " ";
		delete(f);
		f = r;
		if(r!=NULL) r = r->next;
	}
}

int main()
{
	int n=5;
//	cout << "n=";
//	cin >> n;
	node *first; first = NULL;
	node *p;
	int s[5] = { 50,40,30,20,10 };
	for (int i = 0; i < n; i++) {
//		cin >> s;
		p = new node;
		p->w = s[i];
		p->next = first;
		first = p;
	}
	int d=45;
//	cout << "el=";
//	cin >> d;
	insert(d, first);
	wypisz(first, n);
    return 0;
}

