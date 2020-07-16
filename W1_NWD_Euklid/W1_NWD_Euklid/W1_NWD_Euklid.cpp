// tydz1_NWD_Euklid.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int a, b;
	cin >> a; cin >> b;
	while ((a != 0) && (b != 0)) {
		if (a >= b) {
			a = a % b;
		}
		else {
			if (b >= a) {
				b = b % a;
			}
		}
	}
	cout << b + a << endl;

	return 0;
}

