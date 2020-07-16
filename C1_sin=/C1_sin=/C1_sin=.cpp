// C1_sin=.cpp: определяет точку входа для консольного приложения.
//sum(n=0,inf)((-1)^n  *x^2n   /    (2n)! )=sin(x);

#include "stdafx.h"
#include "iostream"

using namespace std;

double silnia (double m) {
	double s = 1;
	for (double i = 1; i <= m; i++) {
		s *= i;
	}
	return(s);
}


int main()
{
	double E = 0.001;
	double cos0, cos1, n, x;
	cin >> x;
	cos1 = 0;
	n = 0;
	do {
		cos0 = cos1;
		cout << n << " ";
		cos1 += (pow(-1, n)*pow(x, 2 * n)) / silnia(2 * n);
		n++;
	} while (abs(cos1 - cos0) > E);
	double c = cos(x);
	cout << endl;
	cout << c << endl;
	cout << cos1 << endl;
    return 0;
}

