#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
using namespace std;

int partition(int tab[], int left, int right) {
	int x = tab[right];
	int j = left - 1;
	int i;
	for (i = left; i<right; i++) {
		if (tab[i] <= x) {
			j++;
			swap(tab[i], tab[j]);
		}
	}
	j++;
	swap(tab[i], tab[j]);
	return j;
}

void quickSort(int tab[], int left, int right) {
	if (right - left>0) {
		int k = partition(tab, left, right);
		quickSort(tab, left, k - 1);
		quickSort(tab, k, right);
	}
}

void quckSortOg(int tab[], int left, int right) {
	qhile(left < right) {
		int k = partition(tab, left, right);
		quckSortOg(t, left, k);
		left = k;
	}
}

int main() {
	int n;
		scanf("%d", &n);
		int *tab = new int[n];
		for (int i = 0; i<n; i++) {
			scanf("%d", &tab[i]);
		}

		quickSort(tab, 0, n - 1);
		for (int i = 0; i<n; i++) {
			printf("%d\n", tab[i]);
		}
		delete[] tab;
}
