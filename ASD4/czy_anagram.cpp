// ASD4.cpp : Defines the entry point for the console application.
// dwa slowa A i B, n literek w kazdym. czy sa anogramami

#include "stdafx.h"
#include <iostream>
using namespace std;

bool anagram(char A[], char B[]) {
	int k = 26;
	int *sign[k];
	for (int i = 0, i < k; i++) sign[i] = 0;
	for (int i = 0; i < n; i++) sign[(int)(A[i] - 'a')]++; //  result[(int)(B[i] - 'a')]++;
	for (int i = 0; i < n; i++) sign[(int)(B[i] - 'a')]++;
	for (int i = 0; i < n; i++) if (sign[i] != 0) return false;
	return true;
}

bool anagram10000() {  //alfabet duzodluzszy niz slowo, mamy duzo pamieci i malo czasu
	int k = 10000;
	int *sign[k];
	for l in a sign[l] = 0; for l in b sign[l] = 0;
	for l in a sign[l]++; for l in b sign[l]--;
	for l in a if sign[l] != 0 return false; for l in b if sign[l] != 0 return false;
	//for (int i = 0, i < k; i++) sign[i] = 0;
	for (int i = 0; i < n; i++) sign[(int)(A[i] - 'a')]++; //  result[(int)(B[i] - 'a')]++;
	for (int i = 0; i < n; i++) sign[(int)(B[i] - 'a')]++;
	for (int i = 0; i < n; i++) if (sign[i] != 0) return false;
	return true;

}

int main()
{
	return 0;
}

