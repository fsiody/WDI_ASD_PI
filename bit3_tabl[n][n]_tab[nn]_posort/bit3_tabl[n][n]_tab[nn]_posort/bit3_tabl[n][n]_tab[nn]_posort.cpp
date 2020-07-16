// bit3_tabl[n][n]_tab[nn]_posort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int wn = 4, kn = 4;

int main()
{
	int t2[wn][kn];
/*	for (int w = 0; w < wn; w++) {
		for (int k = 0; k < kn; k++) {
			t2[w][k] = rand();
		}
	}
*/
	int t1[wn*kn];
	for (int i = 0; i < wn*kn; i++) {
		t1[i] = 0;
	}

	t2[0][0] = 3;
	t2[0][1] = 5;
	t2[0][2] = 7;
	t2[0][3] = 8;

	t2[1][0] = 2;
	t2[1][1] = 3;
	t2[1][2] = 5;
	t2[1][3] = 15;

	t2[2][0] = 1;
	t2[2][1] = 1;
	t2[2][2] = 7;
	t2[2][3] = 13;

	t2[3][0] = 8;
	t2[3][1] = 9;
	t2[3][2] = 9;
	t2[3][3] = 9;

	int ind[wn];
	for (int i = 0; i < wn; i++) {
		ind[i] = 0;
	}
	int mem = 0;
	int min = INT_MAX;
	for (int i = 0; i < wn*wn; i++) {
		min = INT_MAX;
		for (int w = 0; w < wn; w++) {
			if (ind[w] < wn && t2[w][ind[w]] < min) {
				min = t2[w][ind[w]];
				mem=w;
			}
		}
		ind[mem]++;
		t1[i] = min;
	}
	
	for (int i = 0; i < wn*kn; i++){
		cout << t1[i] << " ";

	}



    return 0;
}

