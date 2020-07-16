// bin.poisk.2016.x^x.cpp: ���������� ����� ����� ��� ����������� ����������.
//����� ����� � ����� ��� �^X=2016. ��������, ������� ������ ������������
// �������� � 1 � � 8 (1^1=1, 8^8>>2016)

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, x, y, eps;
	a = 1;
	b = 8;
	eps = 1e-5;
	y = 2016;
	while (abs(b - a) > eps) {
		x = (a + b)*0.5;
		if (exp(x*log(x)) > y) {
			b = x;
		}
		else {
			a = x;
		}
	}
	cout << "x^x=2016" << endl;
	cout << "x=" << x << endl;
    return 0;
}

