// sito_eratosf.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int n = 1000;
	bool p[n];
	p[0] = p[1] = false;
	for (int i = 2; i < n; i++) {
		p[i] = true;
	}
	for (int i = 2; i < sqrt(n); i++) {
		if (p[i]) {
			for (int j = i*i; j < n; j += i) {
				p[j] = false;
			}
		}
	}
	for (int i = 2; i < n; i++) {
		if (p[i]) cout << i << " ";
	}
    return 0;
}

