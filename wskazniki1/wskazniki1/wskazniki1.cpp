// wskazniki1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int ile;
	cin>>ile;
	int *tabl;
	int *w;
	tabl = new int[ile]; // [od jakiego adresu zarezerwowac pamiec]
	w = &tabl[0];
	for (int i = 0; i < ile; i++) {
	//	cout << (int)tabl << endl;  // adresy zapisane 0x 
	//	tabl++;
		w++; // ���������� �� ������� ������� - ���������� "������� ������" ��� ���
		cout << *w << endl;
	}
	delete[] tabl; //zwolniamy pam
	return 0;
}

