// C3_czy int_w_tab_liczb_podz_a.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 10;

int main()
{
	int t[max];
	for (int i = 0; i < max; i++) {
		t[i] = rand();
	}
	int n;
	cin >> n;
	bool flag = false;
	for (int i = 0; i < max && !flag; i++) {
		if (t[i] % 13 == 0) flag = true;
	}
	if (flag) cout << "tak";
	else cout << "nie";

    return 0;
}

