// Z1_3_podciagF=suma.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 1000;

int main()
{
	int fib[max];
	for (int i = 0; i < max; i++) {
		fib[i] = 0;
	}
	fib[1] = fib[0] = 1;
	for (int i = 2; i < max; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}
	int suma;
//	cin >> suma;
	for (int t = 0; t < 3017; t++) {
		suma = t;
		int s = 0;
		bool flag = false;
		int k = 0;
		for (int i = 0; (i < max) && !flag; i++) {
			k = i;
			while (s < suma) {
				s += fib[k];
				k++;
			}
			if (s == suma) {
				s = 0;
				flag = true;
				cout << t << "   tak" << endl;
			}
			else s = 0;
		}
	}
    return 0;
}

