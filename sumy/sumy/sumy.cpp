// sumy.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void skl(int m, int p, string s) {
	if (m == 0) cout << s << endl;
	for (int i = p; i <= m; i++) {
		if (s == "") {
			skl(m - i, i, to_string(i) + s);
		}
		else {
			skl(m - i, i, to_string(i) + "+" + s);
		}
	}
}

int main()
{
	int n;
	cout << "n=";
	cin >> n;
	skl(n,1,"");
    return 0;
}

