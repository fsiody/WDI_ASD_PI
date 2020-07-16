// w1.3_rozkl_na_pierwsze.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int a, a0;
	cin >> a;
	a0 = a;
	while (a % 2 == 0) {
		a = a / 2;
		cout << 2 << endl;
	}
	int i = 3;
	while (i <= sqrt(a0)) {
		while (a % i == 0) {
			a /= i;
			cout << i << endl;
		}
		i += 2;
	}

    return 0;
}

