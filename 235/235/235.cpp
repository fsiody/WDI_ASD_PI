// 235.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n, i;
	i = 0;
	cin >> n;
	for (int i2 = 1; i2 < n; i2 *= 2) {
		for (int i3 = i2; i3 < n; i3 *= 3) {
			for (int i5 = i3; i5 < n; i5 *= 5) {
				cout << i5 << endl;
				i++;
			}
		}
	}
	cout << "all=" << i << endl;
    return 0;
}

