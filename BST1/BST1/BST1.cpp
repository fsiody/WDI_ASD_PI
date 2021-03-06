// BST1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"
#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

struct BSTnode {
	int val;
	int licznik;
	BSTnode* right;
	BSTnode* left;
	BSTnode* parent;
};

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
}

BSTnode* min(BSTnode* root) {
	while (root->left != NULL)root = root->left;
	return root;
}

BSTnode* max(BSTnode* root) {
	while (root->right != NULL)root = root->right;
	return root;
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

void in_order_tree_walk(BSTnode* node) {
	if (node->left != NULL) {
		in_order_tree_walk(node->left);
	}
	for (int i = node->licznik; i > 0; i--) {
		printf("%d\n", node->val);
	}
	if (node->right != NULL) {
		in_order_tree_walk(node->right);
	}
}

int main() {
	/*
	* test data:
	* Z - number of test cases
	* N - number of insert values
	* N values to insert
	* Output:
	* min
	* max
	* N-X lines od numberts
	*/
	srand(time(NULL));
	int Z;
	scanf("%d", &Z);

	for (int i = 0; i < Z; i++) {
		int N;
		scanf("%d", &N);

		BSTnode* tree = NULL;

		int x;
		// insert
		for (int j = 0; j < N; j++) {
			scanf("%d", &x);
			add_node(tree, x);
		}

		printf("%d\n", min(tree)->val);
		printf("%d\n", max(tree)->val);
		in_order_tree_walk(tree);

		// cleanup
		free_BST(tree);
	}

	BSTnode *res = NULL;
	BSTnode* els = new BSTnode;
	els->val = 9999;
	els->licznik = 1;
	els->left = NULL;
	els->right = NULL;
	els->parent = NULL;
	BSTnode* tmp = new BSTnode;
	tmp->val = 11;
	tmp->licznik = 1;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	res = tmp;
	tmp = els;
	cout << res->val << "    " << tmp->val << endl;

	return 0;
}
