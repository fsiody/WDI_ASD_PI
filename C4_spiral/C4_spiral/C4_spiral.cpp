// C4_spiral.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 10;
void kwadrat(int tab[max][max], int &liczn, int n, int i) {
	int w = i; int k = i;
	for (int t = 0; t < n; t++) {
		tab[w][k++] = liczn++;
	}
	k--;
	for (int t = 0; t < n-1; t++) {
		tab[++w][k] = liczn++;
	}
	for (int t = 0; t < n-1; t++) {
		tab[w][--k] = liczn++;
	}
	for (int t = 0; t < n - 2; t++) {
		tab[--w][k] = liczn++;
	}
}

int main()
{
	int tab[max][max];
	int n = max;
	int liczn = 0; int i = 0;

	for (int t = 0; t < max; t++) {
		for (int k = 0; k < max; k++) {
			tab[t][k] = 0;
		}
	}

	while (n > 1) {
		kwadrat(tab, liczn, n, i);
		i++;
		n -= 2;
	}
	if (n == 1) tab[i][i] = liczn;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
/*	int liczn1 = 0;
	int liczn2 = 0;
	int i1 = 0;
	int i2 = 0;

	liczn1 = i1++;
	liczn2 = ++i2;


	cout << "liczn1 = i1++;" << endl;
	cout << "liczn1 = " << liczn1 << endl;
	cout << "i1=" << i1 << endl;
	cout << endl;


	cout << "liczn2 = ++i2;" << endl;
	cout << "liczn2 = " << liczn2 << endl;
	cout << "i2=" << i2 << endl;
	cout << endl;

*/
	

    return 0;
}

