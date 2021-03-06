// wskazniki_first.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include "iostream"
// setlocale(NULL, "Russian");

using namespace std;

struct node {     
	int val;
	node *next;
};
const int max = 20;

void scalic(node * &firsta, node * &firstb) {
	node *firstc; firstc = NULL;
	node *pc; node *pa; node *pb; pa = firsta; pb = firstb;
	while (pa != NULL || pb != NULL) {
		pc = new node;
		pc->next = firstc;
		if (pa != NULL && pb != NULL) {
			if (pa->val < pb->val) {
				pc->val = pa->val;
				pa = pa->next;
				firstc = pc;
			}
			else {
				pc->val = pb->val;
				pb = pb->next;
				firstc = pc;
			}
		}
		else {
			while (pa != NULL) {
				pc = new node;
				pc->next = firstc;
				pc->val = pa->val;
				pa = pa->next;
				firstc = pc;
			}
			while (pb != NULL) {
				pc = new node;
				pc->next = firstc;
				pc->val = pb->val;
				pb = pb->next;
				firstc = pc;
			}
		}
	}
	pc = firstc;
	cout << endl << endl;
	cout << "C" << endl;
	while (pc != NULL) {
		cout << pc->val << "  ";
		pc = pc->next;
	}
	cout << endl;

}

node *scalic_rek(node *fa, node *fb) {
	if (fa == NULL) return fb;
	if (fb == NULL) return fa;
	if (fa->val < fb->val) {
		fa->next= scalic_rek(fa->next, fb);
		return fa;
	}
	else {
		fb->next= scalic_rek(fa, fb->next);
		return fb;
	}
}

void sc_rek(node * &fa, node * &fb) {


	node *fc = scalic_rek(fa, fb);
	fa = fb = NULL;
	while (fc != NULL) {
		cout << fc->val << "  ";
		fc = fc->next;
	}
}

int main()
{
	int max = 10;
	node *firsta; firsta = NULL;          // самый первый элемент, изначально его нет
	node *firstb; firstb = NULL;
	node *pa, *pb;                        // создаваемый элемент, ставим его перед first
	int sa = 110; int sb = 200;
	int a = 3; int b = 5;

	for (int i = 0; i < max; i++) {
		pa = new node; pb = new node;                       // выделяем память под новый элемент
		pa->next = firsta;      pb->next = firstb;            // новый элемент указывает на старый первый, ставим новый перед первым
		pa->val = sa - a;  pb->val = sb - b;                 // приписываем новому элементу его int значение  
		a += 1;     b += 20;
		firsta = pa;       firstb = pb;                  // теперь это наш новый первый элемент
	}

	pa = firsta;
	cout << "A" << endl;
	while (pa != NULL) {
		cout << pa->val<<"  ";
		pa = pa->next;
	}
	cout << endl;
	cout << endl;

	pb = firstb;
	cout << "B" << endl;
	while (pb != NULL) {
		cout << pb->val<<"  ";
		pb = pb->next;
	}
	cout << endl;

	scalic(firsta, firstb);
	cout << endl << endl;
	sc_rek(firsta, firstb);

	return 0;
}

