// pary_ab=s.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int n = 10;

int main()
{
	int t[n][n];
	for (int i = 0; i < n*n; i++) {/*		for (int j = 0; j < n; j++) {*/			t[i / n][i%n] = rand() % 100;	cout << t[i / n][i%n]<<"  "; if (i%n == n - 1) cout << endl;	}
	int k = 0;
	int s; cin >> s;
	for (int i = 0; i < (n*n)-1; i++) {
		for (int j = i + 1; j < n*n; j++) {
			if (t[i / n][i%n] * t[j / n][j%n] == s) {
				k++;
				cout << k << ")  t[" << i / n << "][" << i % n << "] * t[" << j / n << "][" << j % n << "]=" << t[i / n][i%n] << "*" << t[j / n][j%n] << "=" << s << endl;
			}
		}
	}
	cin >> k;
    return 0;
}

