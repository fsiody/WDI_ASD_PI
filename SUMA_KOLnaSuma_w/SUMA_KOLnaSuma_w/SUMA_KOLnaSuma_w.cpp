// SUMA_KOLnaSuma_w.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int max = 10;
	int t[max][max];
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			t[i][j] = rand() % 100 + 1;
			cout << t[i][j] << "    ";
		}
		cout << endl;
	}
	int k[max];
	int w[max];
	for (int i = 0; i < max; i++) {
		k[i] = 0;
		w[i] = 0;
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			w[i] = w[i] + t[i][j];
			k[j] = k[j] + t[i][j];
		}
	}
	int kl, wr, max_k, min_w;
	kl = max_k =  INT_MIN;
	wr = min_w = INT_MAX;
	for (int i = 0; i < max; i++) {
		if (k[i] > kl) {
			kl = k[i];
			max_k = i;
		}
		if (w[i] < wr) {
			wr = w[i];
			min_w = i;
		}
	}
	cout << (double)kl / wr << "=" << max_k << "/" << min_w << endl;
	for (int i = 0; i < max; i++) {
		cout << k[i] << "    ";
	}
	for (int i = 0; i < max; i++) {
		cout << w[i] << endl;
	}
    return 0;
}

