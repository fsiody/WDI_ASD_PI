// rek_liczba_skl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include <string>

using namespace std;

void skl(int n, int p, string s) {
	if (n == 0) cout << s << endl;
	else {
		for (int i = p; i <= n; i++) {
			skl(n - i, i, s + "+" + to_string(i));
		}
	}

}

int main()
{

	int n;
	cin >> n;
	skl(n, 1, "");
    return 0;
}

