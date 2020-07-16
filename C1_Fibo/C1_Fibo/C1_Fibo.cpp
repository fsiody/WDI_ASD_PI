// C1_Fibo.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int f1, f2;
	f1 = 1; f2 = 1;
	cout << f1 << endl; cout << f2 << endl;
	while (f2 < 1e6) {
		f2 += f1;
		f1 = f2 - f1;
		cout << f2 << endl;
	}
    return 0;
}

