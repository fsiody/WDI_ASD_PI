// ulamek.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

struct ulamek {
	long int l;
	long int m;
};

void writ(ulamek u) {
	cout << u.l / u.m << ".";
	u.l %= u.m;
	if (u.l == 0) cout << 0 << endl;
	else {
		for (int i = 0; i < 50; i++) {
			u.l *= 10;
			cout << u.l / u.m;
			u.l %= u.m;
		}
	}
}

void okres(ulamek u) {
	cout << u.l / u.m << ".";
	u.l %= u.m;
	if (u.l > 0) {
		cout << "(";
		int mem = u.l;
		do {
			u.l *= 10;
			cout << u.l / u.m;
			u.l %= u.m;
		} while (u.l != mem);
		cout << ")" << endl;
	}
	else cout << 0 << endl;
}

bool f25(ulamek u) {
	long int i2 = 0;
	long int i5 = 0;
	while (u.m % 2 == 0) {
		u.m /= 2;
		i2++;
	}
	while (u.m % 5 == 0) {
		u.m /= 5;
		i5++;
	}
	if (u.m == 1) return(true);
	else return(false);
}
 /*
void numer(long int a) {
	ulamek u;
	u.l = a;
	u.m = 999999999;
	while(u.l!=)

 } */

int main()
{
	setlocale(LC_CTYPE, "rus");
	ulamek ul;
	cout << "licznik=";
	cin >> ul.l;
	cout << "mianownik=";
	cin >> ul.m;
	bool b = f25(ul);
	if(b) writ(ul);
	else okres(ul);
	/*cout << "явл€ютс€ ли 794 106 770, 063 409 36 26, 093 010 25 93 дробью?" << endl;
	long int LP = 794106770;
	long int LU = 634093626;
	long int GU = 930102593;
	long int NT;
	bool a;
	cout << "¬ведите номер телефона" << endl;
	cin >> NT;
	numer(LP);
	numer(LU);
	numer(GU);
	numer(NT);*/
    return 0;
}

