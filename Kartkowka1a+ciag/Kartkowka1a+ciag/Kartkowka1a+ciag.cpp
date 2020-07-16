// Kartkowka1a+ciag.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int n = 17;

int ciag(int t[]) {
	int max_dlugosc = 0;
	int dlugosc = 0;
	int suma_a = t[0];
	int suma_i = 0;
	if (suma_a == suma_i) dlugosc++;
	bool flag = true;


//	for(int j=1;j<n-1;j++){

		
	for (int i = 1; i < n ; i++) {
	flag = true;
		for (int j = i; j < n  && flag; j++) {
			suma_a += t[j];
			suma_i += j;

			if ((j<n) && (t[j] >= t[j + 1])) {
				if (suma_a == suma_i) {
					dlugosc++;
					if (max_dlugosc < dlugosc) {
						max_dlugosc = dlugosc;
					}
				}
				dlugosc = 0;
				suma_a = 0;
				suma_i = 0;
				flag = false;
			}
			else {
				if (suma_a == suma_i) {
					dlugosc++;
					if (max_dlugosc < dlugosc) {
						max_dlugosc = dlugosc;
					}
				}
				else {
					if (suma_a > suma_i) {
						if (t[j] > j) {
							flag = false;;
							if (max_dlugosc < dlugosc) {
								max_dlugosc = dlugosc;
							}
							dlugosc = 0;
							suma_a = 0;
							suma_i = 0;
						}
						else {
							dlugosc++;
						}

					}
					if (suma_a < suma_i) {
						dlugosc++;
					}
				}
			}
		}
		if (max_dlugosc < dlugosc) {
			max_dlugosc = dlugosc;
		}
	}
	return(max_dlugosc);
}

	int main()
{
	int t[n] = { 0,1,2,0,7,5,6,7,8,0,1,2,3,4,5,7,78 };
//	for (int i = 0; i < n; i++) {
//		cin >> t[i];
//	}
	cout << ciag(t) << endl;

	for (int i = 0; i < n; i++) {
		cout << t[i] << " ";
	}
    return 0;
}

