// C1_pierw_Newton.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	double iter, E1, E2, x, x0, a;
	x = 1;
	cout << "a=";
	cin >> a;
	cout << "iter=";
	cin >> iter;
	cout << "E1=";
	cin >> E1;
	cout << "E2=";
	cin >> E2;
	for (int i = 0; i < iter; i++) {
		x = 0.5 * (x + a / x);
	}
	cout << "x1=" << x << endl;

	x = 1;
	do
	{
		x0 = x;
		x = 0.5 * (x + a / x);
	} while (abs(x - x0) > E1);
	cout << "x2=" << x << endl;

	x = 1;
	do {
		x0 = x;
		x = 0.5 * (x + a / x);
	} while (abs(x - x0) > E2);
	cout << "x3=" << x << endl;
    return 0;
}

