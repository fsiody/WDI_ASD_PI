// huffman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct Sign {
	char ch;
	float n;
	string code;
	Node* el;
};

struct Node {
	Node* left, *right, *parrent;
	Sign leter;
};

void bubble(Sign A[], int i) {
	int j;
	for (j = i + 1; A[j].n < A[i].n; j++) {
		Sign tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
}

Node* create_tree(Sign A[]) {
	for (int i = 0; A[i + 1].n != 0; i++) {
		Node* node2;
		Node* node1;
		if (!A[i].el) {
			node1 = new Node;
			node1->leter.ch = A[i].ch;
			node1->leter.n = A[i].n;
			node1->left = NULL;
			node1->right = NULL;
//			node1->leter.code = "0" + node1->leter.code;
		}
		else node1 = A[i].el;
		if (!A[i + 1].el) {
			node2 = new Node;
			node2->leter.ch = A[i + 1].ch;
			node2->leter.n = A[2].n;
			node2->left = NULL;
			node2->right = NULL;
//			node2->leter.code = "1" + node2->leter.code;
		}
		else node2 = A[i + 1].el;
		Node* parr = new Node;
		parr->leter.n = node1->leter.n + node2->leter.n;
		parr->left = node1;
		parr->right = node2;
		node2->parrent = parr;
		node1->parrent = parr;
		A[i+1].n = node1->leter.n + node2->leter.n;
		A[i+1].el = parr;
		bubble(A, i+1);
	}
}

// zmienic porzadek na rosnacy
int Pivot(Sign A[], int left, int right) {
	for (int i = left;  i >= right; i++) {
		if (A->n != 0)return A->n;
	}
	return -1;
}
void qs(Sign A[], int left, int right, int pivot) {
	int l = left;
	int r = right;
	while (r - l > 0) {
		while (A[r].n > pivot) r++;
		while (A[l].n < pivot)l--;
		if (r - l > 0) {
			Sign tmp = A[r];
			A[r] = A[l];
			A[l] = tmp;
		}
	}
	qs(A, left, r - 1, Pivot(A, left, l - 1));
	qs(A, r + 1, right, Pivot(A, l + 1, right));
}


string encode(string word) {
	Sign result[32];
	for (int i = 0; i < 32; i++) {
		result[i].ch = 0;
		result[i].n = 0;
		result[i].el = NULL;
	}
	for (int i = 0; word[i] != 0; i++) {
		int j = word[i] % word.size;
		result[j].ch = word[i];
		result[j].n += 1 / word.size;
	}
	qs(result, 0, 31, Pivot(result, 0, 31));
	create_tree(result);
	Node* root = create_tree(result);


}

string decode(Node*root, string hword, int i,string code) {
	if (!root) return code;
	if (hword[i] == 0) return decode(root->left, hword, i + 1, code + "0");
	return decode(root->right, hword, i + 1, code + "1");
}


int main()
{
	string word;
	cout << "word=";
	cin >> word;
	encode(word);


    return 0;
}

