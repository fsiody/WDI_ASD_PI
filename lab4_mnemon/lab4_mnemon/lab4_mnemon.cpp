// lab4_mnemon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
// #define DEBUG 1 



using namespace std;


struct Node
{
	string text;
	Node *next;
};

unsigned int hashfunc(string txt) {
	int waga = 65599; unsigned int sum = 0;
	for (int i = 0; txt[i] != 0; i++) {
		sum = (sum * waga + txt[i]);
	}
	return sum;
}

void add_to_hashtable(Node** hashtable, int n, string txt) {
	unsigned int h = hashfunc(txt);
	int start = h % n;
	Node *el = new Node;
	el->text = txt;
	el->next = hashtable[start];
	hashtable[start] = el;

}

bool check_if_exists(Node** hashtable, int n, string txt) {
	unsigned int h = hashfunc(txt);
	int start = h % n;

	Node *tmp = hashtable[start];
	while (tmp != NULL) {
		if (tmp->text == txt) return true;
		tmp = tmp->next;
	}
	return false;
}

void free_memory(Node** hashtable, int n) {
	Node *ptr, *nxt;
	for (int i = 0; i < n; i++) {
		ptr = hashtable[i];
		while (ptr != NULL) {
			nxt = ptr->next;
			delete ptr;
			ptr = nxt;
		}
	}
	delete[](hashtable);
}

void debug_print_hashtable(Node** hashtable, int n) {
#ifdef DEBUG
	Node* ptr;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		ptr = hashtable[i];
		while (ptr != NULL) {
			cout << ptr->text << " | ";
			ptr = ptr->next;
		}
		cout << endl;
	}
#endif
}

int main() {
	ios::sync_with_stdio(false);
	int Z;
	cin >> Z;
	while (Z--) {
		int n, k;
		string tmp;

		cin >> n;
		cin >> k;

		Node** hashtable = new Node*[n]();

		for (int i = 0; i < n; i++)
			hashtable[i] = NULL;

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			add_to_hashtable(hashtable, n, tmp);
		}

		debug_print_hashtable(hashtable, n);

		for (int i = 0; i < k; i++) {
			cin >> tmp;
			if (check_if_exists(hashtable, n, tmp)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}

		free_memory(hashtable, n);

	}

}
