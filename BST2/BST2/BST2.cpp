// BST2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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
}

BSTnode* min(BSTnode* root) {
	while (root->left != NULL)root = root->left;
	return root;
}

BSTnode* max(BSTnode* root) {
	while (root->right != NULL)root = root->right;
	return root;
}

BSTnode* remove_node(BSTnode* root, int value) {
	if (root == NULL) {
		return NULL;
	}
	BSTnode *tmp = root;
	if (value < root->val) {
		root->left=remove_node(root->left, value);
		return root;
	}
	else if (value > root->val) {
		root->right=remove_node(root->right, value);
		return root;
	}
	else {
		if (root->licznik > 1) {
			root->licznik--;
			return root;
		}

		if (root->left == NULL) {
			return root->right;
		}
		else if (root->right == NULL) {
			return root->left;
		}

		// node with two children: The inorder successor is the new value
		BSTnode* temp = min(root->right);

		// Copy the inorder successor's content to this node
		root->val = temp->val;

		// Delete the inorder successor
		root->right = remove_node(root->right, temp->val);
	}
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
	* N, X - number of insert values, number of deleted values
	* N values to insert
	* X values to remove
	* Output:
	* N-X lines od numberts
	*/
	srand(time(NULL));
	int Z;
	scanf("%d", &Z);

	for (int i = 0; i < Z; i++) {
		int N, X;
		scanf("%d %d", &N, &X);

		BSTnode* tree = NULL;

		int x;
		// insert
		for (int j = 0; j < N; j++) {
			scanf("%d", &x);
			add_node(tree, x);
		}
		// remove
		for (int j = 0; j < X; j++) {
			scanf("%d", &x);
			tree = remove_node(tree, x);
		}

		in_order_tree_walk(tree);

		// cleanup
		free_BST(tree);
	}

	return 0;
}