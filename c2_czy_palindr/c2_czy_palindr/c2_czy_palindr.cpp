// c2_czy_palindr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	m = 0;
	int kn = n;
	while (kn > 0) {
		m = m*10+kn % 10; kn /= 10;
	}
	if (m == n) cout << "palindrom";
	else cout << "nie palindrm";
	cout << endl;
    return 0;
}

