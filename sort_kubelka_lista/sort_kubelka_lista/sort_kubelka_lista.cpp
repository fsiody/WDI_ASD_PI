// sort_kubelka_lista.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node
{
	double val;
	Node *next;
	Node()
	{
		this->next = NULL; 
	}
	Node(double val)
	{
		this->val = val;
		this->next = NULL;
	}
};

void insertSort(Node* list)
{
	Node *res = new Node;
	Node *tmp, *restmp = res;
	while (list->next != NULL) {
		tmp = list->next;

		list->next = list->next->next; // wypinam
		while (restmp->next != NULL && restmp->next->val < tmp->val) //lecę na odpowiednie miejsce
			restmp = restmp->next;

		tmp->next = restmp->next; //wstawiam
		restmp->next = tmp;
		restmp = res;
	}
	list->next = res->next;
	delete res; // usuwam wartownika

}

void sort(Node *list)
{
	Node **buckets = new Node*[10];
	Node **head = new Node*[10]; // ostatni element bucketów
	for (int i = 0; i < 10; i++) {
		head[i] = buckets[i] = new Node; //wartowniki
	}
	Node *curr = list;
	while (curr->next != NULL) { // rozwalam na buckety
		int idx = (int)curr->next->val;
		head[idx]->next = curr->next;
		curr->next = curr->next->next;
		head[idx] = head[idx]->next;
	}
	for (int i = 0; i < 10; i++)
	{
		head[i]->next = NULL;
		insertSort(buckets[i]); // sortuje insertem
	}
	Node *sorted = curr = new Node;
	for (int i = 0; i < 10; i++)   // łącze
	{
		if (buckets[i]->next != NULL)
		{
			curr->next = buckets[i]->next;
		}
		while (curr != NULL && curr->next != NULL)
		{
			curr = curr->next;
		}
	}
	delete[] buckets;
	delete[] head;
	list->next = sorted->next;
}

int main()
{
	Node *list = new Node();
	Node *curr = list;
	Node *temp = new Node(5.5);
	curr->next = temp;
	curr = curr->next;
	for (int i = 5; i>0; i--)
	{
		temp = new Node(i / 10.0);
		curr->next = temp;
		curr = curr->next;
	}
	for (int i = 5; i>0; i--)
	{
		temp = new Node(2 + i / 10.0);
		curr->next = temp;
		curr = curr->next;
	}
	sort(list);
	curr = list->next;
	while (curr != NULL)
	{
		cout << curr->val << endl;
		curr = curr->next;
	}
	return 0;
}