// BST3.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

typedef struct BSTnode {
	int val;
	int licznik;
	struct BSTnode* right;
	struct BSTnode* left;
	struct BSTnode* parent;
} BSTnode;

void add_node(BSTnode* &root, int value) {
	BSTnode* tmp = new BSTnode;
	tmp->val = value;
	tmp->licznik = 1;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;

	if (root == NULL) {
		root = tmp;
		return;
	}

	BSTnode* tmpRoot = root;
	BSTnode* prevRoot = NULL;

	while (tmpRoot != NULL) {
		prevRoot = tmpRoot;
		if (tmpRoot->val == value) {
			tmpRoot->licznik++;
			return;
		}
		if (tmpRoot->val < value) tmpRoot = tmpRoot->right;
		else tmpRoot = tmpRoot->left;
	}

	if (prevRoot->val < value) prevRoot->right = tmp;
	else prevRoot->left = tmp;
	tmp->parent = prevRoot;
}


void free_BST(BSTnode* root) {
	if (root == NULL) {
		return;
	}
	if (root->left != NULL) {
		free_BST(root->left);
	}
	if (root->right != NULL) {
		free_BST(root->right);
	}
	delete root;
	return;
}

BSTnode* min(BSTnode* root) {
	while (root->left != NULL)root = root->left;
	return root;
}
BSTnode* max(BSTnode* root) {
	while (root->right != NULL)root = root->right;
	return root;
}

BSTnode* succ(BSTnode* node) {
	BSTnode *r;
	if (node->right != NULL) {
		return min(node->right);
	}
	else {
		r = node->parent;
		while (r!=NULL && (node==r->right)) {
			node = r;
			r = r->parent;
		}
		return r;
	}
	return node;
}

BSTnode* search(BSTnode* root, int val) {
	if (root == NULL || root->val == val) {
		return root;
	}
	if (root->val < val) {
		return search(root->right,val) ;
	}
	return search(root->left, val);;
}

int sum_in_range(BSTnode* node, int min_value, int max_value) {
	BSTnode* left = search(node, min_value);
	BSTnode * right = search(node, max_value);
	int sum = 0;
	while (left != right) {
		for(int i=left->licznik;i>0;i--) sum += left->val;
		left = succ(left);
	}
	sum += right->val; //suming the last element
	return sum;
}

int main() {
	/*
	* test data:
	* Z - number of test cases
	* N, MIN, MAX - number of insert values, min range, max range
	* N values to insert
	* Output:
	* sum
	*/
	srand(time(NULL));
	int Z;
	scanf("%d", &Z);

	for (int i = 0; i < Z; i++) {
		int N, MI, MA;
		scanf("%d %d %d", &N, &MI, &MA);

		BSTnode* tree = NULL;

		int x;
		// insert
		for (int j = 0; j < N; j++) {
			scanf("%d", &x);
			add_node(tree, x);
		}

		int sum = sum_in_range(tree, MI, MA);
		printf("%d\n", sum);

		// cleanup
		free_BST(tree);
	}
	return 0;
}
