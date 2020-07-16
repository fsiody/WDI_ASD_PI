// W3_n=reverse(n).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 15;

/* long long int reverse(int x) {
	long long int w = 0;
	while (x > 0) {
		w = 10 * w + x % 10; x /= 10;
	}
	return(w);
} */

int leng(int (&n)[max]) {
	int i = max-1;
	while (n[i] == 0) {
		--i;
	}
	if (i == -1) i++;
	return(i);
}

void rev(int (&n)[max], int (&rn)[max]) {
	int i = 0;
	int len = leng(n);
	while (len >= 0) {
		rn[i] = n[len];
		i++;
		len--;
	}
}

int main()
{

	int n [] = { 1,2,9,0,0,0,0,0,0,0,0,0,0,0,0 };
	int rn [max];
	for (int l = 0; l < max; l++) {
		rn[l] = 0;
	}
	rev(n, rn);
	bool flag = false; 
	int mem = 0;
	while (!flag) {
		for (int j = 0; j < max; j++) {
			n[j] = n[j] + rn[j] + mem;
			mem = n[j] / 10;
			n[j] %= 10;
		}
		rev(n, rn);
		flag = true;
		for (int l = 0; l < max; l++) {
			if (rn[l] != n[l]) flag = false;
		}
	}



	cout << endl;
	n[0] += 1;
	for (int j = 1; j < max; j++) {
		n[j] += n[j - 1] / 10;
		n[j - 1] %= 10;
	}





	for (int i = 0; i < max; i++) {
		cout << n[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < max; i++) {
		cout << rn[i] << " ";
	}


	/*
	int n[max];
	int rn[max];
	for (int i = 0; i < max; i++) {
		n[i] = 0;
		rn[i] = 0;
	}
	n[0] = 1;

	rev(n, rn);
	int mem = 0;
	int len = 1;
	bool flag;


	for (int i = 1; i < max; i++) {
		len = leng(n);
		rev(n, rn);
		flag = true;
		for (int k = 0; k < max; k++) {
			if (rn[k] != n[k]) flag = false;
		}


		while (!flag) {
			for (int j = 0; j < max; j++) {
				n[j] = n[j] + rn[j] + mem;
				mem = n[j] / 10;
				n[j] %= 10;
			}
			rev(n, rn);
			flag = true;
			for (int l = 0; l < max; l++) {
				if (rn[l] != n[l]) flag = false;
			}
		}
		cout << " " << i << ") ";
		len = leng(n);
		for (int j = len; j >= 0; j--) cout << n[j];
		cout << endl;
		n[0] += 1;		
		for (int j = 1; j < max; j++) {
			n[j] += n[j - 1] / 10;
			n[j - 1] %= 10;
		}
	} */
    return 0;
}

