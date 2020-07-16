// C4_max_podciag_rosn.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max=10;

int main()
{
	int t[max];
	for (int i = 0; i < max; i++) {
		t[i] = rand();
		cout << t[i] << " ";
	}
	cout << endl;
	int len = 1, len_max=0;
	for (int i = 0; i < max - 1; i++) {
		if (t[i + 1] > t[i]) len++;
		else if (len>len_max) {
			len_max = len;
			len = 1;
		}
	}
	cout << len_max;

    return 0;
}

