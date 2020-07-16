// W_ostatnia_niezerowa!.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 214000;

void mnozenie(int(&a)[max], int k) {
	int i=0;
	i = 0;
	int mem=0;
	for (i = 0; i < max; i++) {
			a[i] = a[i] * k + mem;
			mem = a[i] / 10;
			a[i] %= 10;
	}
}


int main()
{
	int n, ki, licznik;
//	cin >> n;
	int silnia[max];
	for (n = 20000; n <= 20000; n++) {
		licznik = 0;
		for (int i = 0; i < max; i++) {
			silnia[i] = 0;
		}
		silnia[0] = 1;
		for (int i = 1; i <= n; i++) {
			ki = i;
			while (ki % 5 == 0) {
				ki /= 5;
				licznik++;
			}
	//		for (int j = licznik; j > 0; j--) {
	//			ki /= 2;
	//		}
			mnozenie(silnia, i);
		}
		cout << n << ".ost=" << silnia[licznik] << endl;
	}
    return 0;
}

