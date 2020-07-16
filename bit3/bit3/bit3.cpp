// bit3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 10;

int main()
{
//	zapisac tablice kolumnami
	cout << "***0***   zapisac tablice kolumnami" << endl;
	cout << endl;

	int t[max][max];
	int el = 1;
	for (int w = 0; w < max; w++) {
		for (int k = 0; k < max; k++) {
			t[k][w] = el;
			el++;
		}
	}

	for (int w = 0; w < max; w++) {
		for (int k = 0; k < max; k++) {
			cout << t[w][k] << " ";
		}
		cout << endl;
	}



//	t2[n][m] <-> t1[n*m]
//<-
	cout << endl;
	cout << "***1.1****   t2[n][m] <- t1[n*m]" << endl << endl;
	int n = 5;
	int m = 2;
	int t1[10];
	int t2[5][2];
	int i = 0;
	for (int i = 0; i < 10; i++) {
		t1[i] = i;
	}
	for (int w = 0; w < n; w++) {
		for (int k = 0; k < m; k++) {
			t2[w][k] = t1[i++];
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << t1[i] << " ";
	}
	cout << endl; cout << endl;

	for (int w = 0; w < n; w++) {
		for (int k = 0; k < m; k++) {
			cout << t2[w][k] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "***1.2***    t2[n][m] <- t1[n*m]" << endl << endl;

	for (int i = 0; i < (n*m); i++) {
		t2[i / n][i%n] = t1[i];
	}

	for (int w = 0; w < n; w++) {
		for (int k = 0; k < m; k++) {
			cout << t2[w][k] << " ";
		}
		cout << endl;
	}

    return 0;
}

