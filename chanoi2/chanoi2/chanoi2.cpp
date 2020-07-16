// chanoi2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void h(int n, char a, char b, char c) {
	if (n > 0) {
		h(n - 1, a, c, b);
		cout << a << "->" << b << endl;
		h(n-1,b, a, c);
	}
}

int main()
{
	int kil;
	cin >> kil;
	char aa, bb, cc;
	aa = 'a';
	bb = 'b';
	cc = 'c';
	h(kil, aa, bb, cc);
    return 0;
}

