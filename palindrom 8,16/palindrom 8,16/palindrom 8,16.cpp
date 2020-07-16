// palindrom.cpp: определяет точку входа для консольного приложения.
//является ли число num палиндромом? osnowa-ричная система исчисления?


#include "stdafx.h"
#include <iostream>

using namespace std;

int reverse2(int n) {
	int m = 0;
	while (n > 0) {
		m = m * 10 + n % 10; n /= 10;
	}
	return (m);
}

int reverse(int n, int osn) {
	int m = 0;
	while (n > 0) {
		m = m * 10 + n % osn; n /= osn;
	}
	return (m);
}

int main()
{
	int num, pal, osnowa;
	while (true) {
		cout << "n=";
		cin >> num;
		cout << "osnowa=";
		cin >> osnowa;
		if (osnowa != 10) {
			num = reverse(num, osnowa);
			pal = reverse2(num);
		}
		else {
			pal = reverse2(num);
		}
		if (num == pal) {
			cout << "TAK, n" << osnowa << "=" << pal << endl;
		}
		else cout << "NIE, n" << osnowa << "=" << pal << endl;
	}
	return 0;
}