// Z1_9_liczby_zaprzyjaznione.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 1000000;

int main()
{
	bool t[max];
	for (int i = 0; i < max; i++) {
		t[i] = true;
	}
	int s1, s2;
	int n2 = 0;
	for (int n1 = 1; n1 < max; n1++) {
		s1 = 0;
		if (t[n1]) {
			for (int i = 1; i < n1; i++) {
				if (n1%i == 0) {
					s1 += i;
				}
			}
			if ((s1 > 0) && (s1 != n1)) {
				n2 = s1;
				s2 = 0;
				for (int i = 1; i < n2; i++) {
					if (n2%i == 0) {
						s2 += i;
						//				cout << i << "  ";
					}
				}
				if (n1 == s2) {
					t[n1] = t[n2] = false;
					cout << n1 << " * " << n2 << endl;
				}
			}
		}
	}
    return 0;
}

