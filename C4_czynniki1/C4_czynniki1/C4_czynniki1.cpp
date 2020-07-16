// C4_czynniki1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int n;
	cin >> n;
	bool *t=new bool [n+1];
	for (int i = 0; i <= n; i++) {
		t[i] = true;
	}
	t[0] = false; t[1] = false;

	for (int i = 2; i*i <= n; i++) {
		for (int j = i*i; t[i] && j <= n; j += i) {
			t[j] = false;
		}
	}

	for (int i = 2; i*i <= n; i++) {
		while (t[i] && n%i == 0) {
			cout << i << " ";
			n /= i;
		}
	}

	delete [] t;
    return 0;
}

