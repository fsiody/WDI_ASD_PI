// rek_suma_liczb_t.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int n=10;

int suma(int t[], int i, int sum) {
	if (i == 0) return sum + t[0];
	suma(t, i - 1, sum + t[i]);
}

int main()
{
	int t[n];
	for (int i = 0; i < n; i++) {
		t[i] = rand() % 100;
		cout << t[i] << " ";
	}
	cout << endl;
	cout << suma(t, n - 1, 0);
    return 0;
}

