// G1_2_najmn_el_2017.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n;
	cin >> n;
	int f1, f2; 
	int start = 1;
	f2 = 1;
	while (f2 != n) {
		f1 = start;
		f2 = start;
		while (f2 < n) {
			f2 += f1;
			f1 = f2 - f1;
		}
		if (f2 != n) {
			start += 1;
		}
	}
	cout << start << endl;
    return 0;
}

