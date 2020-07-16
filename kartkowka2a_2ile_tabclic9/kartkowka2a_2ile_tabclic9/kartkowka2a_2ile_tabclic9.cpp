// kartkowka2a_2ile_tabclic9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void tablica(int t[], bool bylo[], int wsk, int el,int &k) {
	t[wsk] = el;
	if (wsk == 8) {
		k++;
		cout << k << ")  ";
		for (int i = 0; i < 9; i++) {
			cout << t[i] << "  ";
		}
		cout << endl;
	}
	else {
		bool pierwsze[] = { 0,0,1,1,0,1,0,1,0,0 };
		for (int nel = 2; nel < 10; nel++) {
			if ((nel < 10) && (abs(nel - el) > 2) && ((!pierwsze[el]) || (!pierwsze[nel])) && (!bylo[nel])) {
				bylo[nel] = true;
				tablica(t, bylo, wsk + 1, nel, k);
				bylo[nel] = false;
			}
		}
	}
}


int main()
{
	int t[9];
	t[0] = 1;
	int k = 0;
	bool bylo[] = { 1,1,0,0,0,0,0,0,0,0 };
	tablica(t, bylo, 0, 1,k);
    return 0;
}

