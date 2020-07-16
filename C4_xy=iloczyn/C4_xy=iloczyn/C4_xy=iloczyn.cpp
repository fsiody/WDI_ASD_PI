// C3_xy=iloczyn.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 2;

int pary(int n[max][max], int iloczyn) {
	int kk, ww;
	int l = 0;
	for (int w = 0; w < max; w++) {
		for (int k = 0; k < max; k++) {
			if (iloczyn%n[w][k] == 0) {
				if (k == max) { kk = 0;  ww = w + 1; }
				else { kk = k + 1; ww = w; }
				for (; ww < max; ww++) {
					for (; kk < max; kk++) {
						if (n[w][k] * n[ww][kk] == iloczyn) l++;
					}
					kk = 0;
				}
			}
		}
	}
	return(l);
}

int main()
{
	int iloczyn;
	cin >> iloczyn;
	int n[max][max];
	{
		n[0][0] = 2;
		n[0][1] = 2;
		n[1][0] = 4;
		n[1][1] = 1;
	}

	/*
	for (int i = 0; i < max; i++) {
	for (int j = 0; j < max; j++) {
	cin >> n[i][j];
	}
	}  */

	int m = pary(n, iloczyn);
	cout << m << endl;
	return 0;
}

