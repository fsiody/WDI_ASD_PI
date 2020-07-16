// function.i.pntr-referencja.cpp: определяет точку входа для консольного приложения.
//передача функции оригинального значения переменной (массива) ерез указатели

#include "stdafx.h"
#include <iostream>

using namespace std;

float srednica(float *tab, int n) {
	float suma = 0;
	for (int i = 0; i < n; i++) {
		suma += *tab;
		*tab = 999;
		tab++;
	}
	return suma / n;
}

int main()
{
	float tablica[3];
	tablica[0] = 0;
	tablica[1] = 1;
	tablica[2] = 2;
	cout << "srednica=" << srednica(tablica, 3) << endl;
	cout << "komorka tablicy=" << tablica[0] << endl;
	return 0;
}

