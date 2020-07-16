// Z1_7_sito_eratosfena.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 200;

int main()
{
	bool t[max];
	for (int i = 0; i < max; i++) {
		t[i] = true;
	}
	t[0] = t[1] = false;
	for (int i = 2; i*i < max; i++) {
		if (t[i]) {
			for (int j = i*i; j < max; j += i) {
				if (t[j] % t[i] == 0) t[j] = false;
			}
		}
	}
	for (int i = 0; i < max; i++) {
		if (t[i]) cout << i << "  ";
	}
    return 0;
}

