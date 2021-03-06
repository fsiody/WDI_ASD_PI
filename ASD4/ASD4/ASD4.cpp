// ASD4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

const int MAX = 10;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

/***********************************************************************************
***------------------------------------------------------------------------------***
************************************************************************************/
//n-ty en wzgledem wielkosci
int seek(int tab[], int n, int left, int right) {
	int l1 = left; int r1 = right;
	int pivot = tab[(right+left)/2];
	while (left < right) {
		while (tab[left] < pivot)
			left++;
		while (tab[right] > pivot)
			right--;
		if (left < right)
			swap(tab[right], tab[left]);
	}
		if (right+1 == n)
			return right;
		if (right+1 > n)
			return seek(tab, n, l1, right-1);
		else
			return seek(tab, n, left+1, r1);
}
void nty_element(int tab[]) {
	int n; cout << "n="; cin >> n;
	//for (int i = 0; i < MAX; i++) cin >> tab[i];
	tab[0] = 3; tab[1] = 4; tab[2] = 1; tab[3] = 5; tab[4] = 2; tab[5] = 8; tab[6] = 6; tab[7] = 77; tab[8] = 9; tab[9] = 0;
	cout << tab[seek(tab, n, 0, MAX - 1)] << endl;
}
/***********************************************************************************
***------------------------------------------------------------------------------***
************************************************************************************/

// dwa slowa A i B, n literek w kazdym. czy sa anogramami
bool anagram(char A[], char B[], int n) {
	int k = 26;
	int sign[26];
	for (int i = 0; i < k; i++) sign[i] = 0;
	for (int i = 0; i < n; i++) sign[(int)(A[i] - 'a')]++; //  result[(int)(B[i] - 'a')]++;
	for (int i = 0; i < n; i++) sign[(int)(B[i] - 'a')]++;
	for (int i = 0; i < n; i++) if (sign[i] != 0) return false;
	return true;
}
 /*
bool anagram10000() {  //alfabet duzodluzszy niz slowo, mamy duzo pamieci i malo czasu
	int sign[10000];
	int l;
	for (l in a) sign[l] = 0; for (l in b) sign[l] = 0;
	for (l in a) sign[l]++; for (l in b) sign[l]--;
	for (l in a) if sign[l] != 0 return false; for (l in b) if sign[l] != 0 return false;
} */

/***********************************************************************************
***------------------------------------------------------------------------------***
************************************************************************************/


//kopiec - przyda sie na kolos
//struck - w czasie log insert i usuwanie mediany


// k tablic posortowanych, lacznie n el, scalic w O(nlogk) czasie 

int main()
{
	int *tab = new int[MAX];
	nty_element(tab);

	
    return 0;
}


