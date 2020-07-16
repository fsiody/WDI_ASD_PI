// ASD4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int seek(int tab[], int n, int left, int right) {
	int l1 = left; int r1 = right;
	int k = tab[(left + right) / 2];
	while (left < right) {
		while (tab[left] < k) left++;
		while (tab[right] > k)right--;
		if (left < right) swap(t[right, t[left]]);
		if (MAX - right == n)return tab[right];
		if (MAX - right > n)return seek(tab, n, left, r1);
		else return seek(tab, n, l1, right);
	}
}

int main()
{
	return 0;
}

