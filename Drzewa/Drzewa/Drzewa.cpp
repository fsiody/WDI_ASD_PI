// BST3.cpp : Defines the entry point for the console application.
// 1. zaimplementować funkcje sprawdzającą czy drzewo binarne jest drzewem BST
//2. zaimplementować funkcje sprawdzającą czy drzewo binarne jest drzewem AVL
//3. Dane jest drzewo BST, napisać funkcję zwracającą wskaźnik do elementu będącego medianą

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
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
BSTnode* maximum(BSTnode* root) {
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
		while (r != NULL && (node == r->right)) {
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
		return search(root->right, val);
	}
	return search(root->left, val);;
}

int sum_in_range(BSTnode* node, int min_value, int max_value) {
	BSTnode* left = search(node, min_value);
	BSTnode * right = search(node, max_value);
	int sum = 0;
	while (left != right) {
		for (int i = left->licznik; i>0; i--) sum += left->val;
		left = succ(left);
	}
	sum += right->val; //suming the last element
	return sum;
}

BSTnode* remove_node(BSTnode* root, int value) {
	if (root == NULL) {
		return NULL;
	}
	BSTnode *tmp = root;
	if (value < root->val) {
		root->left = remove_node(root->left, value);
		return root;
	}
	else if (value > root->val) {
		root->right = remove_node(root->right, value);
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
		BSTnode* temp = min(root->right);// node with two children: The inorder successor is the new value 
		root->val = temp->val;// Copy the inorder successor's content to this node
		root->right = remove_node(root->right, temp->val); // Delete the inorder successor
	}
	return root;
}

int points(BSTnode* root) {
	int n = 0;
	if (root == NULL) return n;
	n++;
	if (root->left) n += points(root->left);
	if (root->right) n += points(root->right);
	return n;
}


bool czyBST(BSTnode* root) {
	root = min(root);
	BSTnode*prev = root;
	root = succ(root);
	while (root) {
		if (root->val > prev->val) {
			prev = root;
			root = succ(root);
		}
		else return false;
	}
	return true;
}



int czyAVL(BSTnode* root) {
	if (!root) return 0;
	int lefth = czyAVL(root->left);
	int righth = czyAVL(root->right);
	int height = max(abs(lefth), abs(righth))+1;
	if (right < 0 || left < 0)return -height;
	if (abs(lefth - righth) > 1)return -height;
	else return height;
}




BSTnode* moveinorder(BSTnode* root, int &n) {
	BSTnode* tmp = NULL;
	if(root->left) tmp=moveinorder(root->left, n);
	if (tmp != NULL) return tmp;
	n--;
	if (n == 0) return root;
	if(root->right)  tmp=moveinorder(root->right, n);
	if (tmp != NULL) return tmp;
	return NULL;
}

int mediana(BSTnode* root) {
	int n = points(root);
	int res; int m = (n / 2); int mm = m + 1;
	if (n % 2 == 0) res =moveinorder((root), m)->val;
	else{
		res = (moveinorder(root, (m))->val + moveinorder(root, mm)->val) / 2;
	}
	return res;

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
		int N;
		scanf("%d", &N);

		BSTnode* tree = NULL;

		int x; int n = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &x);
			add_node(tree, x);
		}

		cout << czyAVL(tree) << endl;
		/*
		int sum = sum_in_range(tree, MI, MA);
		printf("%d\n", sum);
		free_BST(tree); //cleanup
		*/
	}
		cout << "NULL>0       " << (NULL > 0) << endl;
		cout << "NULL==0       " << (NULL == 0) << endl;
		cout << "NULL>=0      " << (NULL >= 0) << endl;
		cout<<"NULL<0       " << (NULL < 0) << endl;
	return 0;
}
