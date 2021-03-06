#include "stdafx.h"
#include "iostream"
#include <algorithm>

using namespace std;

struct int1 {
	int x;
	int id;
};

const int MAX = 15;
int1 cpya[MAX];


void cpy(int1 a[], int1 cpya[]) {
	for (int i = 0; i < MAX; i++) {
		a[i] = cpya[i];
	}

}

void wypisz(int1 a[]) {
	for (int i = 1; i < MAX; i++) cout << "  (" << a[i].id << ")" << a[i].x << " ";
	cout << endl << endl;
}

void wstaw_bin(int1 a[]) {
	cout << "wstawienie + wyszukiwanie polowkowe  ---  nie zmienia sie liczba przestawien, tylko porownan" << endl;
	for (int i = 2; i < MAX; i++) {
		a[0] = a[i];
		int l, p, mid;
		l = 1; p = i - 1;
		while (l <= p) {
			mid = (l + p) / 2;
			if (a[mid].x > a[0].x) p = mid - 1;
			else l = mid + 1;
		}
		for (p = i - 1; p >= l; p--) { a[p + 1] = a[p]; }
		a[l] = a[0];
	}
	wypisz(a);
	cpy(a, cpya);
}

void wstaw(int1 a[]) { // DZILIMY NA DWA CIAGI, Z BBB WSTAWIAMY NA ODP MIEJSCE W AAA
	cout << "wstawienie  ---   stabilny, wstawiamy na odp miejsce" << endl;  // STABILNY 
	int x = 0;
	for (int i = 1; i < MAX; i++) {
		a[0] = a[i];
		int j = i - 1;
		while (a[j].x > a[0].x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = a[0];
	}
	wypisz(a);
	cpy(a, cpya);
}

void wybieranie(int1 a[]) { // DZIELIMY NA DWA CIAGI Z BBB WYMIRAMY MIN EL, I WYMIENIAMY GO MIEJSCEM Z 1 EL W AAA
	cout << "wybieranie   ---   niestabilny! gorzej dla prawie posort" << endl; // MNIEJSZA LICZBA PRZESTAWIEN, NIESTABILNY, DLA MALYCH MAX
	int m = -1;
	for (int i = 1; i < MAX - 1; i++) {
		m = i;
		for (int j = i + 1; j < MAX; j++) {
			if (a[j].x < a[m].x) {
				m = j;
			}
		}
		a[0] = a[m];
		a[m] = a[i];
		a[i] = a[0];
	}


	wypisz(a);
	cpy(a, cpya);
}


void booble(int1 a[]) {  // POROWNANIE SASIADOW DOPIKI NIE POSORTOWANE, NAJMN EL-TY "WSPLYWAJA"
	cout << "babelkowe  -  stabilne, prawie posort <3 " << endl; //  KORZYSCI TYLKO W PRZYPADKU PRAWIPOSORT CIAGOW
	int1 x;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = MAX - 1; j > i; j--) {
			if (a[j].x < a[j - 1].x) {
				x = a[j];
				a[j] = a[j - 1];
				a[j - 1] = x;
			}
		}
	}
	wypisz(a);
	cpy(a, cpya);
}

void merge(int1 a[], int start, int srodek, int koniec) {
	int1 *t_pom = new int1[(koniec - start + 1)];
	int k = 0;
	int i = start; int j = srodek + 1;
	while (i <= srodek && j <= koniec) {
		if (a[i].x > a[j].x) { t_pom[k] = a[j]; j++; }
		else { t_pom[k] = a[i]; i++; }
		k++;
	}

	while (i <= srodek) { t_pom[k] = a[i]; k++;	i++; }
	while (j <= koniec) { t_pom[k] = a[j]; k++; j++; }

	for (int i = 0; i <= koniec-start; i++) { a[start + i] = t_pom[i]; }
}

void merge_sort(int1 a[], int start, int koniec) {
	int srodek = (koniec + start) / 2;
	if (koniec != start) {
		merge_sort(a, start, srodek);
		merge_sort(a, srodek + 1, koniec);
		merge(a, start, srodek, koniec);
	}
}

void m_sort(int1 a[]) {
	cout << "merge sort   --- stabilne szybkie" << endl;
	merge_sort(a, 1, MAX - 1);
	wypisz(a);
	cpy(a, cpya);
}

void comsort(int1 a[]) {
	cout << "comsort 1.3 babelkowe   ---   niestabilne" << endl;
	int top, gap; gap = MAX;
	bool swapped = true;
	while (gap > 1 || swapped) {
		gap = max(int(gap / 1.3), 1);
		top = MAX - 1 - gap;
		swapped = false;
		for (int i = 0; i <= top; i++) {
			int j = i + gap;
			if (a[i].x > a[j].x) {
				int1 tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				swapped = true;
			}
		}
	}


	wypisz(a);
	cpy(a, cpya);
}


void quicks_r(int1 a[], int l, int p) {
	int i = l; int j = p;
	int x = a[((i + j) / 2)].x;
	while (i <= j) {
		while (a[i].x < x)i++;
		while (a[j].x > x)j--;
		if (i <= j) {
			int1 tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}

	if(l<j) quicks_r(a, l, j);
	if(p>i) quicks_r(a, i, p);
}

void qs(int1 a[]) {
	cout << "quicksort   ---   szybkie, niestabilny" << endl;
	quicks_r(a, 0, MAX - 1);

	wypisz(a);
	cpy(a, cpya);
}


int main()
{
	int1 a[MAX]; a[0].x = -1; cpya[0].x = -1;
	for (int i = 1; i < MAX; i++) {
		a[i].x = rand() % 20;
		a[i].id = i;
		cpya[i] = a[i];
		cout << "  (" << a[i].id << ")" << a[i].x << " ";
	}
	cout << endl;

	wstaw(a);
	wstaw_bin(a);
	wybieranie(a);
	booble(a);
	comsort(a);
	m_sort(a);
	qs(a);
	return 0;
}

