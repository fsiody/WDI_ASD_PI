// chanoi.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

void hanoi(char a, char b, char c, int n) {
	if (n > 0) {
		cout << a << "->" << c << endl;
	}
	else {
		hanoi(b, a, c, n - 1);
	}
}


int main()
{
	int m;
	cin >> m;
	char a='fir', b='prom', c='last';
	hanoi(a, b, c, m);
    return 0;
}

