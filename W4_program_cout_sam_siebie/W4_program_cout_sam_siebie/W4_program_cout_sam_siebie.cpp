// W4_program_cout_sam_siebie.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "fstream"
#include <string>
#include "iostream"

using namespace std;

int main()
{
	fstream plik;
	string linia;
	plik.open("W4_program_cout_sam_siebie.sln", ios::in);
	/*if (plik.good()) {*/
		while (!plik.eof()) {
			getline(plik,linia);
			cout << linia << endl;
		}
		plik.close();
	


    return 0;
}

