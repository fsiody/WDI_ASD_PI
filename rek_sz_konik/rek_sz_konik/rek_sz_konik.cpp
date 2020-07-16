// rek_sz_konik.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int sx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int sy[8] = { 2,-2,1,-1,2,-2,1,-1 };
const int max = 7;
int t[max][max];

bool rek_skoczek(int t[max][max],int y, int x, int n) {
	t[y][x] = n;
	if (n == max*max) {
		return true;
	}
	for (int i = 0; i < 8; i++) {
		if ((x + sx[i] >= 0) && (x + sx[i] < max) && (y + sy[i] >= 0) && (y + sy[i] < max) && (t[(y + sy[i])][(x + sx[i])]==0)) {
			if (rek_skoczek(t, y + sy[i], x + sx[i], n + 1)) {
				return true;
			}
		}
	}
	t[y][x] = 0;
	return false;
}

bool skoczek(int t[max][max]) {
	if (rek_skoczek(t,0,0,1)) return true;
	return false;
}

int main()
{
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			t[i][j] = 0;
		}
	}

	if (skoczek(t)) {
		cout << "tak" << endl;
	}
	else {
		cout << "nie" << endl;
	}
	
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			cout << t[i][j] << "  ";
		}
		cout << endl;
	}

    return 0;
}

