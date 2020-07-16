// rek_fibo.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int fib[1000];

int fibo(int n) {
	if (n < 3) return 1;
	if (fib[n - 1] == -1) fib[n - 1] = fibo(n - 1);
	if (fib[n - 2] == -1) fib[n - 2] = fibo(n - 2);
	return(fib[n - 1] + fib[n - 2]);
}

int main()
{
	int n;
	
	for (int i = 0; i < 1000; i++) {
		fib[i] = -1;
	}
	fib[1] = fib[2] = 1;
	cin >> n;
	cout << fibo(n) << endl;
	for (int i = 0; i < n; i++) {
		cout << fib[i] << "  ";
	}
    return 0;
}

