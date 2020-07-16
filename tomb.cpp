// greedy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int how_many_ways(string map, int N) {
	if (N == map.length() - 1) return 1;
	int sum = 0;
	string one = "1";
	for (int i = 1; i <= 6 && N + i < map.length(); i++) {
		if (map[N + i] == '1') {
			sum += how_many_ways(map, N + i);
		}
	}
	return sum;
}

int main() {
	int N;
	cin >> N;
	string map;
	cin >> map;
	if (map.size() != N) {
		cout << "Incorrect map size" << endl;
		return -1;
	}
	cout << how_many_ways(map, 0) << endl;
}