// time.bez.pnt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;


int main()
{
	clock_t start, stop; // новый тип переменной, время
	double time;
	int ile;
	int n;
	cout << "n=";
	cin >> n;
	cout << "rozmiar tablicy=";
	cin >> ile; // количество итерайий, время которых хотим знать
	int *tabl;
	tabl = new int[ile];
	start = clock();
	for (int i = 0; i < n; i++) {
		tabl[i] = i;
		tabl[i] += 50;
	}
	stop = clock();
	time = (stop - start) / CLOCKS_PER_SEC;
	cout << "time=" << time << endl;
	delete[] tabl;
    return 0;
}

