// greedeEvents.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

struct Event {
	int start, end;
};

void sort(Event* events, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (events[i].end > events[j].end) {
				Event tmp = events[i];
				events[i] = events[j];
				events[j] = tmp;
			}
		}
	}
}

int how_many_rooms(Event* events, int N) {
	int k = 0;
	int result = 0;
	Event deleted;
	deleted.start = -1;
	deleted.end = -1;
	sort(events, N);
	Event* room = new Event[N];
	room[0] = events[0];
	events[0] = deleted;
	while (k < N - 1) {
		for (int i = 1; i < N; i++) {
			if ((events[i].end != -1) && (events[i].start >= room[k].end)) {
				k++;
				room[k] = events[i];
				events[i] = deleted;
			}
		}
		result++;
		room[k].end = 0;
	}
	return result;
}

/*
3
0800 0900
0830 1000
0900 1030
*/

int main() {
	int N;
	cin >> N;
	Event *e = new Event[N];
	for (int i = 0; i<N; i++) cin >> e[i].start >> e[i].end;

	cout << how_many_rooms(e, N) << endl;
	return 0;
}