#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	//abs najbardziej ujemnej liczby
	int n1 = INT_MIN;
	int modN;
	modN = abs(n1);
	cout << "abs(int_min)=" << modN << endl;

	//najwieksza liczba ++
	int n2 = INT_MAX;
	n2++;
	cout << "int_max++=" << n2 << endl;

	// %  ujemnych
	int p7 = 7;
	int m7 = -7;
	int p6 = 10;
	int m6 = -10;
	int w_pp = p7%p6; cout << "7%6=" << w_pp << endl;
	int w_pm = p7%m6; cout << "7%-6=" << w_pm << endl;
	int w_mp = m7%p6; cout << "-7%6=" << w_mp << endl;
	int w_mm = m7%m6; cout << "-7%-6=" << w_mm << endl;

	//zamienic a i b bez c
	int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	b += a;
	a = b - a;
	b -= a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	return 0;
}

