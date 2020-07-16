// DrogaWTablice.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int max = 2;
int pk, pw, kw, kk;

bool dasie(int t[max][max], int w, int k) {
	if (w == max - 1 && k == max - 1) {
		cout << "TAK!" << endl;
		return true;
	}
	if (k<max - 1 && t[w][k + 1]>t[w][k] && dasie(t, w, k + 1)) return true;
	if (w<max - 1 && t[w + 1][k]>t[w][k] && dasie(t, w + 1, k)) return true;
	return false;
}

int main()
{
	int i, j;
	int t[max][max];
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++) {
			t[i][j] = rand() % 100+rand()%10;
			cout << t[i][j] << "    ";
		}
		cout << endl;
	}
	dasie(t, 0, 0);
    return 0;
}

