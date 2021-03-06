// lista_przeplatanka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node2d {
	int v;
	node2d* r;
	node2d* d;
};
const int n = 5;
const int m = 4;

void przeplatanka(bool t[n][m], node2d* tn[], node2d* tm[]) {
	node2d* tmp = NULL; node2d* p = NULL;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t[i][j]) {
				p = new node2d;
				p->v = i * 10 + j;
				p->r = NULL;
				p->d = NULL;
				tmp = tn[i];
				while (tmp && tmp->r) {
					tmp = tmp->r;
				}
				if(tmp)	tmp->r = p;
				else tn[i] = p;
				

				tmp = tm[j];
				while (tmp && tmp->d) {
					tmp = tmp->d;
				}
				if (tmp) tmp->d = p;
				else tm[j] = p;
			}
		}
	}
}


void przepl2(bool t[n][m], node2d *tn2[], node2d *tm2[]) {
	for (int i = n - 1; i >= 0; i--) tn2[i] = NULL;
	for (int i = m - 1; i >= 0; i--) tm2[i] = NULL;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (t[i][j]) {
				node2d *p = new node2d;
				p->r = tn2[i];
				p->d = tm2[j];
				p->v = i * 10 + j;
				tn2[i] = p;
				tm2[j] = p;
			}
		}
	}
}

int main()
{
	bool t[n][m];
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			t[i][j] = false;
			a = i * 10 + j;
			if (a == 0 || a == 20 || a == 23 || a == 30 || a == 32 || a == 33 || a == 40 || a == 41) t[i][j] = true;
			cout << t[i][j] << "  ";
		}
		cout << endl;
	}

	node2d *tn[n], *tm[m], *tn2[n], *tm2[m];
	node2d *pn, *pm;
	for (int i = 0; i < m || i < n; i++) {
		if (i < n) {
			tn[i] = NULL;
			tn2[i] = NULL;
		}
		if (i < m) {
			tm[i] = NULL;
			tm2[i];
		}
	}

	
	przeplatanka(t, tn, tm);
	przepl2(t, tn2, tm2);
	
	
	pn = tn[0]; pm = tm[0];
	node2d *tmp;
	for (int i = 0; i < n; i++) {
		tmp = tn[i];
		while (tmp) {
			cout << tmp->v << " ";
			tmp = tmp->r;
		}
		cout << endl;
	}
	/*while (pn) {
		tmp = pn;
		while (tmp) {
			cout << tmp->v << "  ";
			tmp = tmp->r;
		}
		pn++;
	}
	while (pm) {
		tmp = pm;
		while (tmp) {
			cout << tmp->v << "  ";
			tmp = tmp->d;
		}
		pm++;
	}*/

    return 0;
}

