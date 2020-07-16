// tydz1_rown_kw.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream" 

using namespace std;

int main()
{
	double a, b, c, d, x1, x2, n;
	cin >> a >> b >> c;
	d = b*b - 4 * a*c;
	if (d >= 0) {
		x1 = (-b + sqrt(d)) / (2 * a);
		cout << "x1=" << x1 << endl;
		x2 = (-b - sqrt(d)) / (2 * a);
		cout << "x2=" << x2 << endl;
	}
	else {
		cout << "no x in R" << endl;
	}
	cin >> n;
	return 0;
}

