// C4_e_z_dokladn1000.cpp: определяет точку входа для консольного приложения.
//e=1/0! + 1/1! + 1/2! + ...

#include "stdafx.h"
#include "iostream"

using namespace std;

const int dokl = 10;

void dodawanie(int e[], int a[], int n, int nz) {
	for (int i = n - 1; i >= nz || e[i] > 9; i--) {
		e[i] += a[i];
		if (e[i] > 9) {
			e[i] %= 10;
			e[i - 1]++;
		}
	}
}

void dzielenie(int a[], int n, int d, int &nz) {
	int mem = 0;
	int p;
	for (int i = nz; i < n; i++) {
		mem = 10 * mem + a[i];
		a[i] = mem / d;
		mem %= d;
		if (i == nz && a[i] == 0) nz++;
	}
}

int main()
{
	
	int e[dokl];
	int a[dokl];
	for (int i = 0; i < dokl; i++) {
		e[i] = 0;
		a[i] = 0;
	}
	e[0] = 5;
	a[0] = 5;
	int nz = 0;

	for (int i = 3; nz < dokl; i++) {
		dzielenie(a, dokl, i, nz);
		dodawanie(e,a,dokl,nz);
	}

	cout << "2.";
	for (int i = 0; i < dokl; i++) {
		cout << e[i];
	}


    return 0;
}

