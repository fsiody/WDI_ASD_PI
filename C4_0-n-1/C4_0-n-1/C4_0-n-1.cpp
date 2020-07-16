// C4_czynniki1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


const int max = 4;

void czynniki(int n, bool t[], bool cz[]) {
	for (int i = 2; i*i <= n; i++) {
		if (t[i] && n%i == 0) { // if cz 1 i n=i*const
			cz[i] = true;
		}
	}

	for (int i = 0; i < max; i++) {
		cout << cz[i] << " ";
	}
	cout << endl;
}


int main()
{
	int tab[max];
	for (int i = 0; i < max; i++) {
		cin >> tab[i];
	}  //zapolnienije tablicy 
	int maxi = 0; // max el
	for (int i = 0; i < max; i++) {
		if (tab[i] > maxi) maxi = tab[i];
	}
	//naszli max el
	bool *cz = new bool[maxi]; //czynniki 1
	bool *t = new bool[maxi]; //sito era


	for (int i = 0; i <= max; i++) {
		t[i] = true;
		cz[i] = false;  //cz nie ma
	}
	t[0] = false; t[1] = false;

	for (int i = 2; i*i <= maxi; i++) {
		for (int j = i*i; t[i] && j <= maxi; j += i) {
			t[j] = false; //wyczerkiwajem
		}
	}


	for (int i = 0; i < max; i++) { //prochodim tab ot 0 el do posl
//		if (abs(tab[i]) >= 0) {
			
			czynniki(tab[i],t, cz);
			for (int j = i+1; j < max; j++) { //tabl za i+1, i+2, ...
				if ((cz[j-i+1]) && (tab[j]>0)) tab[j] = -tab[j]; // if jest czynnik i jeszcze nie -
			} //to meniajem znak

			for (int i = 0; i <= maxi; i++) {
				cz[i] = false; //czystim massiw czynnikow
			}
			
//		}
	}
	if (tab[max - 1] < 0) cout << "TAK";
	else cout << "nie";

	delete[] t;
	delete[] cz;
	
	return 0;
}