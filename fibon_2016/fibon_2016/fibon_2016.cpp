// fibon_2016.cpp: определяет точку входа для консольного приложения.
//  1000000 чисел фибоначчи
// какое число должно быть первым чтобы в ряду появилось число n

#include "stdafx.h"
#include <iostream>

using namespace std;

const int max = 100;
int c[max], a[max], b[max], c[max];

/*

void pl(int d[max], int e[max], int f[max]) {
	int ost;
	ost = 0;
	int k = 0;
	while ((d > 0) && (e > 0)) {
		arr[k] = ((d / 10) + (e / 10) + ost) / 10;
		ost = ((d / 10) + (e / 10) + ost) % 10;
		d %= 10; e %= 10;
		k++;
	}
	while (k > 0) {
		cout << arr[k] << endl;
	}
}
*/

void wypisz(int m, int k) {
	cout << "a" << k << "=";
	while (m > 0) {
		cout<<c[m];
		m--;
	}
}


int main()
{
	for (int i = 0; i < 100; i++) {
		c[i] = 0;
		a[i] = 0;
		b[i] = 0;
	}
	int ost = 0;
	int len = 0;
	a[0] = 1;
	b[0] = 1;
	c[0] = a[0] + b[0];
	cout << "a1=" << a[0] << endl;
	cout << "a2=" << b[0] << endl;
	cout << "a3=" << c[0] << endl;
	for (int i = 0; i < 1000000; i++) {
		 



		wypisz(len, i);
	}



	int n;
	cin >> n;
    return 0;
}

