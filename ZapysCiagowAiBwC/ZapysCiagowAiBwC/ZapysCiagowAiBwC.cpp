// ZapysCiagowAiBwC.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void wypisz(int t[], int m) {
	for (int i = 0; i < m; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
}

void spr(int el, int *ptr, int *tab) {
	bool flag = true;
	for (int j = 0; j < *ptr; j++) {
		if (el == *(tab + j)) flag = false;
	}
	if (flag) {
		*(tab + *ptr) = el;
		*ptr = *ptr + 1;
	}

}

int main()
{
	const int n=10;
	int a[2*n], b[2*n], c[2*n];
	int k;
	a[0] = 1; a[1] = 1; a[2] = 2;
	b[0] = 1; b[1] = 1; b[2] = 1;
	c[0] = 1; c[1] = 2;
	k = 2;
	for (int i = 3; i < n; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2] + b[i - 3];
		if (a[i] < b[i]) {
			spr(a[i], &k, &c[0]);
			spr(b[i], &k, &c[0]);
		}
		else {
			spr(b[i], &k, &c[0]);
			spr(a[i], &k, &c[0]);
		}
	}
	wypisz(a, n);
	wypisz(b, n);
	wypisz(c, k);
    return 0;
}

