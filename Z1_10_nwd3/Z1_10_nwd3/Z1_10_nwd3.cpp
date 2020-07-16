// Z1_10_nwd3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int nwd(int x, int y) {
	while (x != 0 && y != 0) {
		if (x > y) x = x%y;
		else y = y%x;
	}
	return(x+y);
}

int main()
{
	int a, b, c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	int nab, nac, nbc;
	a = nwd(a, b);
	b = nwd(a, c);
	c = nwd(b, c);
	while(a!=b && c!=b) {
		a = nwd(a, b);
		b = nwd(a, c);
		c = nwd(b, c);
	}


	cout << "nwd(a,b,c)=" << a << endl;
    return 0;
}

