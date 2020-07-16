// mergesort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int max = 5;
int t[max];

int merge(int t[],int size, int s) {
	int a = 0; int b = s;
	int *tab=new int [size];
	for (int i = 0; i < size; i++) {
		if (a >= s || b < size&&t[a] > t[b]) {
			tab[i] = t[b]; b++; a++;
		}
		else {
			tab[i] = t[a]; b++; a++;
		}
	}
	for (int i = 0; i < size; i++) {
		t[i] = tab[i];
	}
	return *t;
	delete tab;

}

int sort(int *t, int n) {
	if (n == 1) return t[n];
	sort(t, n / 2);
	sort(t + (n / 2), n - (n / 2));
	return merge(t, n, n / 2);
}

int main()
{
	for (int i = 0; i < max; i++) {
		t[i] = rand() % 100;
		cout << t[i] << "  ";
	}
	cout << endl;
	sort(t, max);
	for (int i = 0; i < max; i++) {
		cout<<t[i]<<"  ";
	}
    return 0;
}

