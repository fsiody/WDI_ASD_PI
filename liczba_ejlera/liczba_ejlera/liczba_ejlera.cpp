// liczba_ejlera.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "число Ёйлера е=1/1!+1/2!+1/3!+...+1/n!=";
	const int max = 1000;
	int e[max];
	int tmp[max];
	for (int i = 0; i < max; i++) {
		e[i] = 0;
		tmp[i] = 0;
	}
	tmp[0] = 1;
	e[0] = 1;
	for (int k = 1; k < 100; k++) {
		int r = 0;
		for (int i = 0; i < max; i++) {
			r = r * 10 + tmp[i];
			tmp[i] = r / k;
			r %= k;
		}
		int p = 0;
		for (int i = 0; i < max; i++) {
			p = p + e[i] + tmp[i];
			e[i] = p % 10;
			p /= 10;
		}
	}
	cout << e[0] << ".";
	for (int i = 1;i< max;i++) {
		cout << e[i];
	}
    return 0;
}

