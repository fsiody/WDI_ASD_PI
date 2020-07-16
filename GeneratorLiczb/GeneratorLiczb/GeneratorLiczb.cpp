// GeneratorLiczb.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int reverse(int k) {
	int m = 0;
	while (k > 0) {
		m = m * 10 + k % 10;
		k /= 10;
	}
	return(m);
}

int main()
{
	int n, ls;
	ls = 0;
	cin >> n;
	for (int i = 0; i < 16; i++) {
		int ki = i;
		int s = 0;
		int kn = n;
		while (ki > 0) {
			if (ki % 2 == 1) {
				s = s*10 + kn % 10;
			}
			ki /= 2;
			kn /= 10;
		}
		s=reverse(s);
		if ((s % 7 == 0) && (s>0)) {
			cout << s << endl;
			ls++;
		}
	}
	cout << "ls=" << ls << endl;
    return 0;
}

