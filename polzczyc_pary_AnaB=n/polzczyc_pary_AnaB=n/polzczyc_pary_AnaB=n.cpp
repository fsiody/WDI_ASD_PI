// polzczyc_pary_AnaB=n.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int max = 100;
	int t[max];
	for (int i = 0; i < max; i++) {
		t[i] = rand() % 100 + 1;
	}
	int s;
	cin >> s;
	for (int i = 0; i < max; i++) {
		if (s%t[i] == 0) {
			for (int j = (i + 1); j < max; j++) {
				if (t[i] * t[j] == s) cout << i << "*" << j << "=" << t[i] <<"*"<< t[j] << "=" << s << endl;
			}
		}
	}
    return 0;
}

