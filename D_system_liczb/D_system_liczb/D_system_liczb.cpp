// D_system_liczb.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	cout << "z 10 systemy kiczbowej -> k" << endl;
	int n10, k; int nk = 0;
	cout << "n10=";
	cin >> n10;
	cout << "k=";
	cin >> k;
	while (n10 > 0) {
		nk = nk * 10 + n10 % k;
		n10 /= k;
	}
	cout << "n" << k << "=" ;
	int knk = nk;
	nk = 0;
	while (knk > 0) {
		nk = nk*10 + knk % 10;
		knk /= 10;
	}
	cout << nk << endl;

	cout << "z k systemy kiczbowej -> 10" << endl;
	int kk = 1;
	while (nk > 0) {
		n10 += (nk % 10) * kk;
		nk /= 10;
		kk *= k;
	}

	cout << "n10=";
	cout << n10;
	cout << endl;
    return 0;
}

