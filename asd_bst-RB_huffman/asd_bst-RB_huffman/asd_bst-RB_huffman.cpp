// asd_bst-RB_huffman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

enum Color {
	R,
	B
};
struct NodeBST {
	int val;
	int n;
	NodeBST *right, *left, *parr;
	Color color;
};

using namespace std;


NodeBST* minN(NodeBST* root) {
	while (root->left != NULL)root = root->left;
	return root;
}
NodeBST* maxN(NodeBST* root) {
	while (root->right != NULL)root = root->right;
	return root;
}

void free_BST(NodeBST* root) {
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
void in_order_tree_walk(NodeBST* node) {
	if (node->left != NULL) {
		in_order_tree_walk(node->left);
	}
	for (int i = node->n; i > 0; i--) {
		cout << node->val << "  ";
	}
	if (node->right != NULL) {
		in_order_tree_walk(node->right);
	}
}


//NodeBST* leaf;
NodeBST* newnode(int val) {
	NodeBST* node = new NodeBST;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	node->color = R;
	node->parr = NULL;
	node->n = 1;
	return node;
}
void add(NodeBST*& root, int val) {
	if (!root) {
		root = newnode(val);
		return;
	}
	if (root->val == val) {
		root->n++;
		return;
	}
	if (val < root->val) {
		if(root->left)	return add(root->left, val);
		root->left = newnode(val);
		root->left->parr = root;
		return;
	}
	if(root->right)	return add(root->right, val);
	root->right = newnode(val);
	root->right->parr = root;
	return;
}


int czy_rb(NodeBST *p) {
	if (!p)return 0;
	int hleft = czy_rb(p->left);
	int hright = czy_rb(p->right);
	int height = max(abs(hleft), abs(hright)) + 1;
	if (hleft < 0 || hright < 0) return -height;
	if ((height - 1) > 2 * min(abs(hleft), abs(hright)) && height!=2) return -height;
	return height;
}



void print_Tree(NodeBST * p, int level)
{
	if (p)
	{
		print_Tree(p->left, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << p->val;//<<"^"<<p->color << endl;
		print_Tree(p->right, level + 1);
	}
}
int main()
{
	NodeBST* root = NULL;
//	leaf = newnode(0);
//	leaf->color = B;
	int n;
	cout << "n=";
	cin >> n;
	int val;
	for (int i = n; i > 0; i--) {
		cin >> val;
		add(root, val);
	}
	cout << endl;
	print_Tree(root, 0);
	int height = czy_rb(root);
	if (height>=0) cout << "TAK" << endl;
	else cout << "NIE" << endl;
	cout << height << endl;

    return 0;
}

