// OstCyfraSilni.cpp: определяет точку входа для консольного приложения.
//найти последнюю ненулевую цифру num!

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int count2, count5;
	count2 = count5 = 0;
	int last = 1;
	int num;
	cin >> num;
	for (int i = 2; i <= num; i++) {
		int n = i;
		while (n % 5 == 0) {
			n /= 5;
			count5++;
		}
		while (n % 2 == 0) {
			n /= 2;
			count2++;
		}
		last = last*(n % 10) % 10;
	}

	count2 = (count2 - count5) % 4;

	switch (count2) {
	case 0: last *= 6; break;
	case 1: last *= 2; break;
	case 2: last *= 4; break;
	case 3: last *= 8; break;
	}
	cout << "ost. niezerowa cyfr ! = " << last % 10 << endl;
    return 0;
}

