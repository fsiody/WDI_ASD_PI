// sqrt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void sq(double bn, double d, double s, double epsi) {
	if (d > epsi) {
		d = abs(0.5 * (s / bn + bn) - bn);
		bn = 0.5 * (s / bn + bn);
		sq(bn, d, s, epsi);
	}
	else {
		cout << "pierwiastek z S =" << bn << endl;
		cout << "sqrt(s)=" << sqrt(s) << endl;
	}
}

int main()
{
	double ep = 1e-10;
	double an = 1;
	double ss, delta;
	cout << "s=";
	cin >> ss;
	delta = abs(0.5 * (ss / an + an) - an);
	sq(an, delta, ss, ep);
    return 0;
}

