// n!_wzor_stirlinga.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "Вычислить n! для n<=1000" << endl;
	const int max = 100;
	int s[max];
	for (int i = 0; i < max; i++) {
		s[i] = 0;
	}
	s[0] = 1;
	int n;
	cin >> n;
	int k5 = n / 5;
	int p = 0;
	for (int i = 1; i <=n; i++) {
		for (int j = 0; j < max; j++) {
			int tmp = s[j] * i + p;
			p = tmp / 10;
			s[j] = tmp % 10;
		}
	}
	if (p > 0) cout << "Таблица мала" << endl;
	else {
		bool b = false;
		for (int i = max; i > 0; --i) {
			if (s[i] > 0) 	b = true;
			if (b) {
				cout << s[i];
				b = false;
			}
		}
		for (int i = 0; i < k5; i++) {
			cout << 0;
		}
		cout<<endl;
	}
    return 0;
}

