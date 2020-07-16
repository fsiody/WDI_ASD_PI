// W2_sum_p(n).cpp: определяет точку входа для консольного приложения.
// szukamy liczby a^p+b^p+...+z^p=ab..z
// nie zalezy od kolejnisci cyfr, generacja zbiorow z powtorzeniami 1-18 cyfr 0..9

#include "stdafx.h"
#include "iostream"

using namespace std;

int sum_p(int x, int p) {
	int p;
	int c;
	int sum = 0;
	for (int j = 0; j < p; j++) {
		c = x % 10;
		x /= 10;
		for (int k = 0; k < p; k++) {
			c *= c;
		}
		sum += c;
	}
	return(sum);
}

int main()
{
	int a = 3;
	int i = 0;
	cout << 2 << endl;
	while (i < 6) {
		if (sum_p(a) == a) {
			cout << a << endl;
			i++;
		}
		a++;
	}
    return 0;
}

