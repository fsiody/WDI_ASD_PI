// Z1_8_liczba_doskonala.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 200;

int main()
{

	for (long long int n = 2; n < 10e5; n++) {
		long long int s = 0;
		for (long long int i = 1; 2*i <= n; i++) {
			if (n%i == 0) s += i;
		}
		if (s == n) cout << n << ";  ";
		if (n % 100 == 0)cout << "**" << n << "**";
	}


    return 0;
}

