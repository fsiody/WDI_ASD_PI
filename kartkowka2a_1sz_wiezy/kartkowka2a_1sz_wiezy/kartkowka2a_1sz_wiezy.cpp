// kartkowka2a_1sz_wiezy.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 4;

int suma(int t[max][max], int w1, int k1, int w2, int k2, int n, int max_s) {
	int s = 0;

	int ruch_w[] = { 0,0,0,-1,1,0,0,-1,1 };
	int ruch_k[] = { 0,-1,1,0,0,-1,1,0,0 };

	int ww1, ww2, kk1, kk2;
	if (n < 5) {
		ww1 = w1 + ruch_w[n];
		kk1 = k1 + ruch_k[n];
		ww2 = w2;
		kk2 = k2;

	}
	else {
		ww1 = w1 + ruch_w[n];
		kk1 = k1 + ruch_k[n];
		ww2 = w2;
		kk2 = k2;
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if ((i == ww1) || (i == ww2) || (j == kk1) || (j == kk2)) s +=t [i][j];
		}
	}

	if (s > max_s) {
		max_s = s;
	}
	if (n == 8) {
		return max_s;
	}

	while (n < 9) {
		n++;
		if (n < 5) {
			if ((w1 + ruch_w[n] >= 0) && (w1 + ruch_w[n] < max) && (k1 + ruch_k[n] >= 0) && (k1 + ruch_k[n] < max) && ((w1 + ruch_w[n] != w2) || (k1 + ruch_k[n] != k2))) {
				return suma(t, w1, k1, w2, k2, n, max_s);
			}
		}
		else {
			if ((w2 + ruch_w[n] >= 0) && (w2 + ruch_w[n] < max) && (k2 + ruch_k[n] >= 0) && (k2 + ruch_k[n] < max) && ((w2 + ruch_w[n] != w1) || (k2 + ruch_k[n] != k1))) {
				return suma(t, w1, k1, w2, k2, n, max_s);
			}
		}
	}
}

bool czy_mozliwo(int t[max][max], int w1, int k1, int w2, int k2) {
	int sum = 0;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++){
			if ((i == w1) || (i == w2) || (j == k1) || (j == k2)) sum += t[i][j];
		}
	}
	cout << sum << endl;
	int s = suma(t, w1, k1, w2, k2, 1, 0);
	cout << s << endl;
	if (s > sum)return true;
	return false;
}

int main()
{
	int t[max][max];
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			t[i][j] = rand() % 21;
			cout << t[i][j] << "    ";
		}
		cout << endl;
	}

	int w1, w2, k1, k2;
	cin >> w1; cin >> k1; cin >> w2; cin >> k2;

	if (czy_mozliwo(t, w1, k1, w2, k2)) cout << "tak" << endl;
	else cout << 'nie' << endl;
    return 0;
}

