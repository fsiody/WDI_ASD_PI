
#include "stdafx.h"
#include <iostream>

using namespace std;

struct Item {
	double value, weight;
	double id;
};

struct Knapsack {
	Item* items;
	int n_elems;
	double capacity;
};



void sort(Knapsack &K) {
	for (int i = 0; i < K.n_elems; i++) {
		for (int j = i + 1; j < K.n_elems; j++) {
			if (K.items[i].id < K.items[j].id) {
				Item tmp = K.items[i];
				K.items[i] = K.items[j];
				K.items[j] = tmp;
			}
		}
	}
}

double max_profit(Knapsack K) {
	for (int i = 0; i < K.n_elems; i++) {
		K.items[i].id = K.items[i].value / K.items[i].weight;
	}
	sort(K);
	double mass = K.capacity;
	double many = 0;
	for (int i = 0; i < K.n_elems && mass > 0; i++) {
		if (mass >= K.items[i].weight) {
			mass -= K.items[i].weight;
			many += K.items[i].value;
		}
		else {
			many += mass * K.items[i].id;
			mass = 0;
		}
	}
	return many;
}
/*
3 10
50 10
10 5
32 8
*/
int main() {
	int N, cap;
	cin >> N >> cap;
	Knapsack k;
	k.n_elems = N;
	k.capacity = cap;
	k.items = new Item[N];
	for (int i = 0; i<N; i++) {
		cin >> k.items[i].value >> k.items[i].weight;
	}

	cout << max_profit(k);
	delete[] k.items;
}
