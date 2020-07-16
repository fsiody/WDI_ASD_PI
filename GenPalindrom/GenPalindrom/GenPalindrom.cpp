// GenPalindrom.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void pal(int a, int b, string wyn) {
	cout << wyn << endl;
	if (a >= 2) {
		pal(a - 2, b, 'A' + wyn + 'A');
		if (a % 2 == 1) pal(a - 1, b, wyn + 'A');
	}
	if (b >= 2) {
		if (b % 2 == 1) pal(a, b - 1, wyn + 'B');
		pal(a, b - 2, 'B' + wyn + 'B');
	}
}

int main()
{
	int na, nb;
	cout << "a=";
	cin >> na;
	cout << "b=";
	cin >> nb;
	pal(na, nb, "");
    return 0;
}

