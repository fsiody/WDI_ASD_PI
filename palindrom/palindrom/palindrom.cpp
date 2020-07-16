// palindrom.cpp: определяет точку входа для консольного приложения.
//является ли число num палиндромом?

#include "stdafx.h"
#include <iostream>

using namespace std;

int reverse(int n) {
	int m=0;
	while (n > 0) {
		m = m * 10 + n % 10; n /= 10;
	}
	return (m);
}

int main()
{
	int num, pal;
	cin >> num;
	pal = reverse(num);
	if (num == pal) {
		cout << "TAK" << endl;
	}
	else cout << "NIE" << endl;
    return 0;
}

