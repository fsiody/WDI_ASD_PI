// Z1_6_podzielniki.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) cout << i << "; ";
	}
    return 0;
}

