// RosnacyPodCiag.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int max_len(int p[], int n, int& f) {
	int len, max_l;
	len = 1;
	max_l = 1;
	for (int i = 0; i < n - 1; i++) {
		if (p[i] < p[i + 1]) len++;
		else {
			if (len > max_l) {
				max_l = len;
				f = i;
			}
			len = 1;
		}
	}
	if (len > max_l) max_l = len;
	return(max_l);
}

int main()
{
	const int max = 1000;
	int t[max];
	for (int i = 0; i < max; i++) {
		t[i] = rand() % 100 + 1;
	}
	int s;
	int l = max_len(&t[max], max, s);
	cout << "len=" << l << endl;
	for (int i = s - l; i <= s; i++) {
		cout<<t[i]<<" ";
	}
    return 0;
}

