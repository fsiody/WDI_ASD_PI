#include "stdafx.h"
#include <iostream>
using namespace std;

int posO(int n, int l) {
	return l % n;
}

int pos1(int n, int l) {
	return l / n;
}

void sort(int n, int *t) {
	int *counters[n];
	int *result[n];
	for (int i = 0; i < n; i++) counters[pos0(t[i])]++;
	for (int i = 1; i < n; i++) counters[i] += counters[i - 1];
	for (int i = n - 1; i >= 0; i--)result[--counters[t[i]]] = t[i];
	for (int i = 0; i < n; i++)t[i] = result[i];
	delete[] counters;
	delete[] result;
}

int main()
{
	return 0;
}