// C1_bisekcja_x^x^=2017.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

double pow2(double a) {
	double w = pow(a, pow(a, a))-2017;
	return(w);
}

int main()
{
	double x = 5;
	double lx = 10;
	double px = 1;
	double E = 0.0001;
	double p = pow2(x);
	while (abs(p) > E) {
		if (p > 0) {
			lx = x;
		}
		if (p < 0) {
			px = x;
		}
		x = (lx + px)*0.5;
		p = pow2(x);
	}
	cout << x << endl;
    return 0;
}

