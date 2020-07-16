#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

int partition(int tab[], int left, int right) {
	int x = tab[right];
	int j = left - 1;
	int i;
	for (i = left; i<right; i++) {
		if (tab[i] <= x) {
			j++;
			swap(tab[i], tab[j]);
			// przenies element do lewej podtablicy
		}
	}
	j++;
	swap(tab[i], tab[j]);
	return j;
}

void quickSort(int tab[], int left, int right) {
	stack qs=new stack;
	push(right, qs);
	push(left, qs);
	while(!empty(qs)) {
		left = pop(qs);
		right = pop(qs);
		if (right - left > 0) {
			int k = partition(tab, left, right);
			push(k - 1,qs);
			push(left,qs);
			push(right,qs);
			push(k,qs);
		}
	}
}

int main() {
	int Z;

	scanf("%d", &Z);

	//	int val;

	while (Z--) {

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
}
