// Kartkowka1a_liczby.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int a, b, ka, kb, system_liczbowy, ia, ib;
	bool flag = false;
	cin >> a;
	cin >> b;
	char cyfry[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	bool powtarzania[16];

	int ax[32];
	int bx[32];

	for (system_liczbowy = 2; !flag && system_liczbowy <= 16; system_liczbowy++) {
		for (int i = 0; i < 32; i++) {
			ax[i] = 0;
			bx[i] = 0;
		}
		for (int i = 0; i < 16; i++) {
			powtarzania[i] = false;
		}
		flag = true;
		ka = a; ia = 0;
		while ((ka > 0) && flag) {
			if (!powtarzania[ka%system_liczbowy]) powtarzania[ka%system_liczbowy] = true;
			else flag = false;
			ax[ia] = ka%system_liczbowy;
			ka /= system_liczbowy; ia++;
		}

		kb = b; ib = 0;
		while ((kb > 0) && flag) {
			if (!powtarzania[kb%system_liczbowy]) powtarzania[kb%system_liczbowy] = true;
			else flag = false;
			bx[ib] = kb%system_liczbowy;
			kb /= system_liczbowy; ib++;
		}
	}
	system_liczbowy--; ia--; ib--;
	cout << "system liczbowy  " << system_liczbowy << endl;
	cout << "a" << system_liczbowy << "=";
	for (; ia > 0; ia--) {
		cout << ax[ia];
	}
	cout << endl;
	cout << "b" << system_liczbowy << "=";
	for (; ib > 0; ib--) {
		cout << bx[ib];
	}


    return 0;
}

