// wskazniki_first.cpp : Defines the entry point for the console application.
// lista; komurka A ma KLUCZ - indez , NEXT - nastepny , ZAJENTA - true/faulse czy zajeta komurka/czy mozna wpisac cos nowego 

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node {
	int klucz;
	int next;
	bool zajeta;
};

const int n = 5;
node memory[n];
int first = 0;
node PUSTA;


int mnew(int kl, int index, int i) {
	if (!memory[index].zajeta) {
		if (first != index) {
			memory[i].next = index;
		}
		memory[index].zajeta = true;
		memory[index].klucz = kl;
		return 0;
	}
	return(-1);
}


void mdelete(int i) {
	memory[i].zajeta = false;
}
int lengt() {
	int len = 0;
	int index = first;
	while (memory[index].zajeta == true) {
		++len;
		index = memory[index].next;
	}
	cout << len << endl;
	return len;
}
bool czy_lczb_w_L_porz(int l) {
	int wart = 0;
	while ((memory[wart].klucz != l) && (memory[wart].zajeta != false)) {
		wart = memory[wart].next;
	}
	if (memory[wart].klucz == l) return true;
	return false;
}
void del_ost() {
	int ind = 0;
	while ((ind < n) && (memory[ind].next != -1)) {
		ind++;
	}
	memory[ind].zajeta = false;
	memory[ind - 1].next = -1;
}


void wst_up(int el) {
	int i = 0;
	int ind = lengt();
	while ((memory[i].klucz < el) && (memory[i].next != -1)) {
		i = memory[i].next;
	}
	if (i == 0) {
		first = ind;
		memory[ind].next = 0;
	}
	else {
		i--;
		memory[ind].next = memory[i].next;
	}
	mnew(el, ind, i);
}

bool czy_istn(int el) {
	int ind = first;
	while ( (memory[ind].next >= 0) && ( memory[ind].klucz!=el ) ) {
		ind = memory[ind].next;
	}
	if (memory[ind].klucz == el) return true;
	return false;
}

void usun(int el) {
	if (czy_istn(el)) {
		int ind = first;
		if (memory[ind].klucz != el) {
			int in = ind; ind = memory[in].next;
			while (memory[ind].klucz != el) {
				in = memory[ind].next;
				ind = memory[in].next;
			}
			memory[in].next = memory[ind].next;
		}
		if (ind == first) first = memory[ind].next;
		memory[ind] = PUSTA;
		
	}
	else cout << "nie istnieje" << endl;
}

int main()
{
	PUSTA.klucz = -1;
	PUSTA.next = -1;
	PUSTA.zajeta = false;
	for (int i = first; i < n; i++) { memory[i] = PUSTA; }
	int mnoz = 1;
	for (int i = first; i < n; i++) { mnoz *= 10;  mnew((rand() % 11)*mnoz, i, i - 1); cout << memory[i].klucz << "  "; }
	cout << endl;
	int leng = lengt();
	if (czy_lczb_w_L_porz(10)) cout << "TAK" << endl;
	else cout << "NIE" << endl;
	del_ost();
	del_ost();
	for (int i = first; i < n && memory[i].zajeta; i = memory[i].next) {
		cout << memory[i].klucz << "  ";
	}
	cout << endl;

	/*
	leng = lengt();
	for (int i = 0; i < leng; i++) {
	cin>>memory[i].klucz;
	} */
	int wstaw;
	cin >> wstaw;

	wst_up(wstaw);

	for (int i = first; i < n && memory[i].zajeta; i = memory[i].next) {
		cout << memory[i].klucz << "  ";
	}
	cout << endl;
	
	usun(9000);

	for (int i = first; memory[i].zajeta; i = memory[i].next) {
		cout << memory[i].klucz << "  ";
	}
	cout << endl;


	return 0;
}

