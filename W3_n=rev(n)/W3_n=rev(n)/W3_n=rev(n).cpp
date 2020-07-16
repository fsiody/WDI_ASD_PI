// W3_n=rev(n).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;



int rev(int n) {
	int i = 0; int rn=0;
	while (n > 0) {
		rn = rn*10 + n%10;
		n /= 10;
	}
	return(rn);
}

int main()
{
	int n;
	int rn;
	bool flag;

	for (int i = 1; i < 200; i++) {
		n = i;
		rn = rev(n);
		flag = true;
		for (int k = 0; k < 200; k++) {
			if (rn != n) flag = false;
		}

		while (!flag) {
			n += rn;
			rn = rev(n);
			flag = true;
			if (rn != n) flag = false;
		}
		cout << " " << i << ") " << n << "********  " << rn << endl;
	}
    return 0;
}

