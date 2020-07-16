// c2_wykreslenie_cyfr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void wykreslic(int) {

}

int main()
{
	int n=2315; //cin >> n;
	int kn = n; int i = -1;;
//	while (kn >= i) {
//		i *= 2;
//		kn--;
//	}
	kn = n; int n2[100];
	for (int j = 0; j < 100; j++) {	n2[j] = 0; }
	int j = 0;
	int nn = 0;
	while (kn > 0) {
		nn =nn*10+ kn % 10; kn /= 10;
	}
	while (nn > 0) {
		n2[j] = nn % 10; nn /= 10; j++;
	}
	int liczba = 0; int k = 0;
	while (liczba < n) {
		liczba = 0;
		i++;
		int ki = i;
		k = 0;
		while (k < j) {
			if (ki % 2 == 1) {
				liczba = liczba * 10 + n2[k];
			}
			k++;
			ki /= 2;
		}
		if (liczba % 7 == 0) cout << liczba << endl;
	}


    return 0;
}

