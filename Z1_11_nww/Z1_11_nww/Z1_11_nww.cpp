// Z1_11_nww.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 2000;

int nb(int a, int b, int c) {
	int n;
	if (a >= b) n = a;
	else n = b;
	if (n < c) n = c;
	return(n);
}


int main()
{
	int a, b, c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	int najb = nb(a, b, c);
	cout << "max_liczba=" << nb(a,b,c) << endl;
	int nww=1;


	int t[max], ta[max], tb[max], tc[max];
	for (int i = 0; i < max; i++) {
		t[i] = 0;
		ta[i] = 0;
		tb[i] = 0;
		tc[i] = 0;
	}
	t[0] = -1; ta[0] = -1; tb[0] = -1; tc[0] = -1;
	t[1] = -1; ta[1] = -1; tb[1] = -1; tc[1] = -1;

	for (int i = 2; i*i <= najb; i++) {
		if (t[i]==0) {
			for (int j = i*i; j <= najb; j += i) {
				t[j] = -1;
				ta[j] = -1;
				tb[j] = -1;
				tc[j] = -1;
			}
		}
	}


	for (int i = 1; i <= a; i++) {
		while (a%i == 0 && t[i]>=0) {
			a /= i;
			ta[i]++;
		}
	}
	for (int i = 1; i <= b; i++) {
		while (b%i == 0 && t[i]>=0) {
			b /= i;
			tb[i]++;
		}
	}
	for (int i = 1; i <= c; i++) {
		while (c%i == 0 && t[i]>=0) {
			tc[i]++;
			c /= i;
		}
	}

	for (int i = 0; i <= najb; i++) {
		if (t[i] >= 0) {
			for( int j = nb(ta[i], tb[i], tc[i]); j>0;j--)	nww *= i;
		}
	}

	cout << "nww=" << nww << endl;
    return 0;
}

