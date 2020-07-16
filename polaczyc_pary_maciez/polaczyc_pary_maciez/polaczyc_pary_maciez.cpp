// polaczyc_pary_maciez.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int max = 100;
	int t[max][max];
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			t[i][j] = rand() % 100 + 1;
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < max; i++) {
		for (int k = 0; k < max; k++) {
			if (s%t[i][k] == 0) {
				for (int j = (i + 1); j < max; j++) {
					for (int l = (k + 1); l < max; l++) {
						if (t[i][k] * t[j][l] == s) {
							cout << i << "," << k << "*" << j << "," << l << "->";
							cout << t[i][k] << "*" << t[j][l] << "=" << s << endl;
						}
					}
				}
			}
		}
	}
    return 0;
}

