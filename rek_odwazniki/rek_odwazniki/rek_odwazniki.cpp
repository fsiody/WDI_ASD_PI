// rek_odwazniki.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 10;

bool odwaz(int t[], int masa, int n, int index) {
	if (masa == 0) return true;
	if (index == n) return false;
	if (masa < 0) return false;
	if (odwaz(t, masa - t[index], n, index + 1) || odwaz(t, masa, n, index + 1) || odwaz(t, masa + t[index], n, index + 1)) {
		return true;
	}
}

bool czy_mozna(int t[], int masa, int n) {
	return odwaz(t, masa, n, 0);
}

int main()
{
//	int n; cin >> n;
	int masa; cin >> masa;
	int t[max];
	for (int i = 0; i < max; i++) {
		cin >> t[i];
	}
	if (czy_mozna(t,masa, max-1)) cout << "TAK" << endl;
	else cout << "nie" << endl;
    return 0;
}

