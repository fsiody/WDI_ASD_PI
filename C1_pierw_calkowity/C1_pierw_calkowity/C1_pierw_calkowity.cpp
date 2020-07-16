// C1_pierw_calkowity.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int i, a, s, sq;
	s = 0; sq = -1; i = 1;
	cin >> a;
	while (a >= s) {
		s += i;
		i += 2;
		sq++;
	}
	cout << sq << endl;
    return 0;
}

