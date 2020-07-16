// n9^9=10^n-1.cpp: определяет точку входа для консольного приложения.
//x=c1c2c3...cn
//s=cq^c2+...+cn^c1
//s=x, n-?

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long int  s, x, n, tmp, c, c2, d;
	for (int i = 10; i <= 1000000000; i++) {
		s = 0;
		cout << i<<" ";
		tmp = i;
		c = tmp % 10; tmp = tmp / 10;
		c2 = c;
		while (tmp > 0) {
			d = tmp % 10; tmp = tmp / 10;
			if ((c != 0) || (d != 0)) {
				s = s + pow(d, c);
			}
			c = d;
		}
		if ((c != 0) || (c2 != 0)) {
			s = s + pow(c2, c);
		}
		if (s == i) {
			cout << "x=" << i << endl;
			break;
		}
	}
}

