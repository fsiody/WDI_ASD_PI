// exam_do_while.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	double i1, j1, i2, j2;
	cin >> i1;
	i2 = i1;
	j1 = j2 = 0;
	do {
		i1 = i1 + 1.0;
		j1 = j1 + 2 * i1;
	} while (i1 > 100);


	i2 = i2 + 1.0;
	j2 = j2 + 2 * i2;
	while (i2 > 100) {
		i2 = i2 + 1.0;
		j2 = j2 + 2 * i2;
	}

	cout << i1 << j1 << endl;

	cout << i2 << j2 << endl;


    return 0;
}

