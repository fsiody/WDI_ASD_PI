// c2_czy palindrom_w_system_n.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n; cin >> n; int baza; cin >> baza; int kn = n;
	int n_baza = 0;
	char t[100];  for (int i = 0; i < 100; i++) { t[i] = '0'; }
	int i = 0;
	char cyfry[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (n > 0) {
		t[i] = cyfry[n%baza]; n /= baza;
		i++;
	}
	int max = --i;
	bool flag = true;
	while (i >= max - i) {
		if (t[i] != t[max - i]) {
			flag = false;
			break;
		}
		i--;
	}
	if (flag)cout << "tak" << endl;
	else cout << "nie" << endl;
	cin >> n_baza;
	kn = n_baza / 10;
	n = 1;
	i = 1;
	int k = 1;
	while (kn > 0) {
		k = 1;
		for (int j = 0; j < i; j++) { k *= baza; }
		n += (kn % 10)*k;
		i++;
		kn /= 10;
	}
	cout << n << endl;
	/*	while (kn > 0) {
	n_baza = n_baza*10 + kn%baza; kn /= baza;
	}
	int n_baza_reverse = 0;
	kn = n_baza;
	while (kn > 0) {
	n_baza_reverse = n_baza_reverse * 10 + kn % 10; kn /= 10;
	}
	if (n_baza_reverse == n_baza) cout << "tak";
	else cout << "nie"; */
	cout << endl;
	return 0;
}

