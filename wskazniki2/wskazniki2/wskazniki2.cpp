// wskazniki2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
{
	//int *tablica;
	int ile;
	cout << "ile = ";
	cin >> ile;
	int *tablica = new int[ile]; // указатель на переменн инт (адрес) = место в куче длины иле
	int *w = tablica; // указатель на указатель
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < ile; i++) {
		*w = i+50;
		w++;
	}
	stop = clock();
	double time = (stop - start) / CLOCKS_PER_SEC;
	cout << "time=" << time << endl;
	cout << "adres ost =" << w << endl;
    return 0; // opa
}

