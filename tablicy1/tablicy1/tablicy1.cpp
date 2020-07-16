// tablicy1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>

using namespace std;

bool perev(int a) {
	bool fl = true;
	int ka = a;
	while (ka > 0 && fl) {
		int cyf = ka % 10; ka /= 10;
		if (cyf % 2 == 0) { fl = false; }
	}
	return (fl);
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int max = 10;
	int t[max];
	for (int i = 0; i < max; i++) {
		t[i] = rand() % 1000+1;
	}
	bool flag;
	bool flag2;
	int j;
	/* */

	cout<<endl;
	cout<<"���������� �� ������� |7? ������� ��?"<<endl;
	flag = false;
	int l = 0;
	for (int i = 0; i < max && !flag; i++) {
		if (t[i] % 7 == 0) {
			l++;
			flag = true;
			//			break;
		}
	}
	if (flag) {
		cout << "TAK, istnieje " << l << " elem. |7" << endl;
	}
	else cout << "NIE" << endl;
	cout << "t[35]="<< t[35] << endl;


	cout << endl;
	cout<<"��� �� �������� ������� |7?"<<endl;
	if (flag = true) {
		for (int i = 0; i < max && flag; i++) {
			if (t[i] % 7 != 0) {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << "kazdy el. t |7  !)" << endl;
	}
	else { cout<<"nie kazdy el. t |7 :(" << endl; } 


	cout << endl;
	cout<<"��������� �� ������� � �������� ��� ����� ��������?"<<endl;
	flag = false;
	flag2 = true; // ���������� ����� �� �� ������ �����. �� ��������� ������ 
	j = -1; // ����� ���� ������� � ��� �������
	for (int i = 0; i < max && !flag; i++) {
		int kel = t[i];
		while (kel> 0 && flag2) {
			int c = kel % 10; kel /= 10;
			if (c % 2 == 0) { flag2 = false; }
		}
		if (flag2) {
			j = i;
			flag = true;
		}
		flag2 = true;
	}
	if (flag) {
		cout << "Istnieje, t[" << j << "]=" << t[j] << endl;
	}
	else { cout << "Nie" << endl; }


	cout << endl;
	cout << "��� �� ����� ����� ������ ���� �������� �����?" << endl;
	flag = true;
	flag2 = false;
	j = -1;
	for (int i = 0; i < max && flag; i++) {
		int kel = t[i];
		while (kel > 0 && !flag2) {
			int c = kel % 10; kel /= 10;
			if (c % 2 == 0) {
				flag2 = true;
			}
		}
		if (!flag2) { flag = false; j = i; }
		else { flag2 = false; }
	}
	if (flag) {
		cout << "TAK" << endl;
	}
	else {
		cout << "Nie, t[" << j << "]=" << t[j] << endl;
	}

	cout << endl;
	cout << "� ������ �� ������ ���. ����� � ������� ��� ����� ��������?" << endl;
	int t2[max][max];
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			t2[i][j] = rand() % 10000;
		}
	}
	flag2 = false;
	flag = true;
	int k=-1;
	for (int i = 0; i < max && flag; i++) {
		flag = false;
		for (int j = 0; j < max && !flag2; j++) {
			flag2=perev(t2[i][j]);
		}
		if (flag2) {
			flag = true;
			flag2 = false;
		}
		else {
			k = i;
		}
	}
	if (flag) { cout << "TAK" << endl; }
	else { 
		cout << "NIE, t2[" <<k<< "]=";
		for (int i = 0; i < max; i++) {
			cout << t2[k][i]<<"  ";
		}
	}
    return 0;

}

