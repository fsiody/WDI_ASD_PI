// sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;


void bubbleSort(int t[], int n) {
	bool action = true;
	for (int i = 1; i < n && action; i++) {
		action = false;
		for (int j = 0; j < n - 1; j++) {
			if (t[j] > t[j + 1]) {
				action = true;
				int tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}
	}
}


void selectionSort(int t[], int n) {
	for (int i = 0; i < n-1; i++) {
		int minId = i;
		for (int j = i + 1; j < n; j++) {
			if (t[minId] > t[j]) minId = j;
		}
		int tmp = t[i];
		t[i] = t[minId];
		t[minId] = tmp;
	}
}

void insectionSort(int t[], int n){
	for (int i = 1; i < n; i++) {
		int val = t[i];
		int j = i - 1;
		while(j >= 0 && t[j] > val){
			t[j+1] = t[j];
			j--;
		}
		t[j+1] = val;
	}
}



int main()
{  

	int t[100];
	int t1[100];
	for (int i = 0; i < 100; i++) {
		t[i] = rand() % 15;
		t1[i] = t[i];
		cout << t[i] << " ";
	}
	cout << endl;
	bubbleSort(t1, 100);
	insectionSort(t, 100);
	for (int i = 0; i < 100; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 100; i++) {
		cout << t1[i] << " ";
	}


    return 0;
}

