// с2_235.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n; cin >> n; int l = 1;
	for (int i = 1; i <= n; i *= 2) {
		for (int j = i; j <= n; j *= 3) {
			for (int k = j; k <= n; k *= 5) {
				cout << l<<")"<<k << endl;
				l++;
			}
		}
	}

    return 0;
}

