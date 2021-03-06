#include "stdafx.h"
#include <iostream>
#include <assert.h>

using namespace std;

struct Node {
	int val;
	Node *next;
};

Node *create_node(int value) {
	Node *new_node = new Node;
	new_node->val = value;
	new_node->next = nullptr;
	return new_node;
}

void print_list(Node *first) {
	while (first != nullptr) {
		cout << first->val << " ";
		first = first->next;
	}
	cout << endl;
}

void print_list_cycled(Node *first) {
	Node *tmp = first;
	do {
		cout << tmp->val << " ";
		tmp = tmp->next;
	} while (tmp != first);
	cout << endl;
}

void print_list_cycled_test(Node *first) {
	Node *tmp = first;
	int i = 0;
	do {
		cout << tmp->val << " ";
		tmp = tmp->next;
	} while (++i < 12);
	cout << endl;
}


void linked_list_to_cycled(Node *&first) {
	Node *tmp = first;
	while (tmp->next != nullptr) tmp = tmp->next;
	tmp->next = first;
}

void add_at_beginning(Node *&first, Node *new_node) {
	if (first == nullptr) {
		first = new_node;
		return;
	}
	new_node->next = first;
	first = new_node;
}

void add_at_end(Node *&first, Node *new_node) {
	if (first == nullptr) {
		first = new_node;
		return;
	}
	Node *tmp_node = first;
	while (tmp_node->next != nullptr) tmp_node = tmp_node->next;
	tmp_node->next = new_node;
}

/**********************************************************************************/
/*
* 2016/2017
Dane są dwie listy cykliczne powstałe przez zapętlenie listy jednokierunkowej posortowanej
rosnąco, dla każdej listy dany jest wskaźnik wskazujący przypadkowy element w takiej liście.
Proszę napisać funkcję, która dla dwóch list cyklicznych, usuwa z obu list elementy
występujące w obu listach. Do funkcji należy przekazać wskaźniki na dwie listy, funkcja
powinna zwrócić łączną liczbę usuniętych elementów.
Uwagi:
- czas na rozwiązanie obu zadań wynosi 45 minut
- za każde zadanie można otrzymać maksymalnie 5 pkt
- oceniane będą: czytelność, poprawność i efektywność rozwiązań
*/

Node *get_last_cycled_sorted_list(Node *first) {
	Node *tmp = first;
	while (tmp->next != first and tmp->next->val >= tmp->val) tmp = tmp->next; // pierwszy warunek w petli jest zabezpieczeniem przed paroma nodeami o takiej samej wartości
	return tmp;
}

void delete_next_nodes(Node *&first1, Node *&first2) {
	Node *tmp1, *tmp2;
	int val = first1->next->val;
	while (first1->next->val == val) { // usuwamy wszystkie elementy (czyli wszystkie kolejne) o tych samych wartościach
		tmp1 = first1->next;
		first1->next = first1->next->next;
		delete tmp1;
	}
	while (first2->next->val == val) {
		tmp2 = first2->next;
		first2->next = first2->next->next;
		delete tmp2;
	}
}
// idea - tak jak na zajęciach tyle że z tą różnicą, że otrzymujemy wskaźnik na ostatni element listy, dzięki czemu pierwszy (i każdy kolejny) możemy "obsłużyć" w jednej pętli.
void zadanie2016A(Node *&list1, Node *&list2) {
	list1 = get_last_cycled_sorted_list(list1);
	list2 = get_last_cycled_sorted_list(list2);
	Node *first1 = list1;
	Node *first2 = list2;
	while (first1->next->val != list1->val or first2->next->val != list2->val) { // generalnie posługuję się ->next->val, a nie po prostu ->next, bo wartości ostatnich elementów mogą się powtarzać
		if (first1->next->val == first2->next->val) delete_next_nodes(first1, first2);
		else if (first1->next->val > first2->next->val) first2 = first2->next;
		else first1 = first1->next;
	}
	// sprawdzamy ostatni element (ewentualnie ostatnie elementy o tej samej wartości)
	if (first1->next->val == first2->next->val) delete_next_nodes(first1, first2);

	list1 = first1->next;
	list2 = first2->next;
}

/**********************************************************************************/
/*
Zbiór liczb naturalnych jest reprezentowany jako jednokierunkowa lista. Y-lista to struktura
reprezentująca dwa zbiory liczb naturalnych (rysunek na wiki).
Proszę napisać funkcję, która dwa zbiory A,B reprezentowane jako Y-lista przekształca w dwa
zbiory reprezentowane jako niezależne listy. Do funkcji należy przekazać wskaźniki do dwóch
list, funkcja powinna zwrócić liczbę elementów części wspólnej zbiorów A,B.

Uwagi:
- ważne: jeżeli część wspólna dwóch zbiorów jest pusta, Y-lista staje się dwoma niezależnymi
listami.
- wartości w listach nie są uporządkowane
*/

struct Y_list {
	Node *branch1;
	Node *branch2;
};

void connect_y_branches(Node *firstX, Node *first3) {
	while (firstX->next != nullptr) firstX = firstX->next;
	firstX->next = first3;
}
// tworzymy jakąś przykładową listę
Y_list *create_y_list() {
	Y_list *y_list = new Y_list;
	y_list->branch1 = y_list->branch2 = nullptr;
	for (int i = 0; i<3; i++) add_at_end(y_list->branch1, create_node(i));
	for (int i = 0; i<5; i++) add_at_end(y_list->branch2, create_node(i));
	Node *common_branch = nullptr;
	for (int i = 0; i<2; i++) add_at_end(common_branch, create_node(i));
	connect_y_branches(y_list->branch1, common_branch);
	connect_y_branches(y_list->branch2, common_branch);
	return y_list;
}

int get_length(Node *first) {
	int length = 0;
	while (first) {
		length++;
		first = first->next;
	}
	return length;
}

void move_forward(Node *&first, int i) {
	while (i > 0) {
		first = first->next;
		i--;
	}
}

int zadanie2016B(Y_list *y_list, Node *&first1, Node *&first2) {
	if (y_list->branch1 == nullptr or y_list->branch2 == nullptr) return 0;
	first1 = y_list->branch1;
	first2 = y_list->branch2;
	int length_branch1 = get_length(first1), length_branch2 = get_length(first2);
	length_branch1 > length_branch2 ? move_forward(y_list->branch1, length_branch1 - length_branch2) : move_forward(y_list->branch2, length_branch2 - length_branch1);

	while (y_list->branch1->next != y_list->branch2->next) {
		y_list->branch1 = y_list->branch1->next;
		y_list->branch2 = y_list->branch2->next;
	}

	int count_elements = 0;
	while (y_list->branch1->next != nullptr) {
		count_elements++;
		y_list->branch2->next = create_node(y_list->branch1->next->val);
		y_list->branch1 = y_list->branch1->next;
		y_list->branch2 = y_list->branch2->next;
	}
	return count_elements;
}
// to tylko test, nie musicie się nim przejmować
bool assert_zadanie2016B(Node *first1, Node *first2) {
	while (first1) {
		Node *tmp = first2;
		while (tmp) {
			if (tmp == first1) return false;
			tmp = tmp->next;
		}

		first1 = first1->next;
	}
	return true;
}

/**********************************************************************************/
/*
Dane są dwa jednokierunkowe łańcuchy odsyłaczowe (listy) zbudowane z elementów:
struct node { int w; node* next; };
Każdy łańcuch zawiera niepowtarzające się liczby naturalne. W obu łańcuchach liczby są posortowane rosnąco.
Proszę napisać funkcję usuwającą z każdego łańcucha liczby nie występujące w drugim. Do funkcji należy przekazać
wskazania na oba łańcuchy, funkcja powinna zwrócić łączną liczbę usuniętych elementów.
*/

void create_sample_lists_zadanie2014B(Node *&first1, Node *&first2) {
	for (int i = 0; i < 5; i++) add_at_end(first1, create_node(i));
	add_at_end(first1, create_node(10));
	for (int i = 3; i < 8; i++) add_at_end(first2, create_node(i));
}

void delete_next_node(Node *&first, Node *&list) {
	Node *tmp = first->next;
	first->next = first->next->next;
	if (tmp == list) list = list->next; // jeżeli usuwamy z początku listy, to ją update'ujemy
	delete tmp;
}

void zadanie2014B(Node *&list1, Node *&list2) {
	Node *first1 = new Node;
	Node *first2 = new Node;
	first1->next = list1; // tworzymy listy pomocnicze mające listy z parametrów na nextie, tak będzie łatwiej usuwać, bo nie będziemy musieli badać dodatkowo pierwszego elementu
	first2->next = list2;
	while (first1->next != nullptr or first2->next != nullptr) {
		if (first1->next == nullptr) delete_next_node(first2, list2); // sprawdzamy najpierw to z nullami, aby przypadekiem nie było "null strzałka równa się pałka". Jeżeli jedna lista jest już dalej nullem, to usuwamy kolejne elementy z tej drugiej
		else if (first2->next == nullptr) delete_next_node(first1, list1);
		else if (first1->next->val > first2->next->val) delete_next_node(first2, list2); // jeżeli któryś z elementów jest mniejszy, do go usuwamy
		else if (first1->next->val < first2->next->val) delete_next_node(first1, list1);
		else { // jeżeli elementy są takie same, to je pomijamy i idziemy dalej
			first1 = first1->next;
			first2 = first2->next;
		}
	}
}

/**********************************************************************************/
/*
* Dana jest lista jednokierunkowa zawierająca liczby naturalne. Liczbę oznaczamy jako niskobitową, jeśli w reprezentacji
* binarnej liczba jedynek jest mniejsza niż 8, średniobitową, gdy liczba jedynek jest pomiędzy 8 a 24 a wysokobitową,
* gdy liczba jedynek przekracza 24. Napisać funkcję, która podzieli listę na trzy listy z liczbami nisko, średnio i
* wysokobitowymi, a następnie złączy te listy w jedną.
*/

int count_ones(int num) {
	int count = 0;
	while (num != 0) {
		if (num % 2 == 1) count++;
		num /= 2;
	}
	return count;
}

void add_to_list(Node *&list, Node *new_node) {
	new_node->next = list;
	list = new_node;
}

Node *merge_lists(Node *first1, Node *first2, Node *first3) {
	Node *first = nullptr;
	while (first1) {
		Node *tmp = first1;
		first1 = first1->next;
		add_to_list(first, tmp);
	}
	while (first2) {
		Node *tmp = first2;
		first2 = first2->next;
		add_to_list(first, tmp);
	}
	while (first3) {
		Node *tmp = first3;
		first3 = first3->next;
		add_to_list(first, tmp);
	}
	return first;
}

void zadanie2011(Node *&first) {
	Node *lower = nullptr, *middle = nullptr, *upper = nullptr;
	while (first) {
		Node *tmp = first;
		first = first->next;
		int ones_amount = count_ones(tmp->val);
		if (ones_amount < 8) add_to_list(lower, tmp);
		else if (ones_amount <= 24) add_to_list(middle, tmp);
		else add_to_list(upper, tmp);
	}
	first = merge_lists(lower, middle, upper);
}


/**********************************************************************************/

int main() {
	Node *first = nullptr;
	for (int i = 0; i<5; i++) add_at_end(first, create_node(i));
	print_list(first);
	linked_list_to_cycled(first);
	print_list_cycled_test(first);
	print_list_cycled(first);
	print_list_cycled(first->next->next);
	print_list_cycled(get_last_cycled_sorted_list(first->next->next));
	cout << endl;

	cout << "zadanie z cyklicznymi:\n";
	// wklepuję do nich jakieś przykładowe dane
	Node *list1 = nullptr;
	Node *list2 = nullptr;
	for (int i = 0; i < 7; i++) {
		add_at_end(list1, create_node(i));
	}
	add_at_end(list2, create_node(2));
	for (int i = 1; i < 7; i++) {
		add_at_end(list2, create_node(2 * i));
	}
	add_at_end(list1, create_node(18));
	add_at_end(list1, create_node(21));
	add_at_end(list1, create_node(21));
	add_at_end(list2, create_node(21));

	linked_list_to_cycled(list1);
	linked_list_to_cycled(list2);
	print_list_cycled(list1);
	print_list_cycled(list2);
	list1 = list1->next->next;
	list2 = list2->next;
	zadanie2016A(list1, list2);
	print_list_cycled(list1);
	print_list_cycled(list2);
	cout << endl;

	cout << "zadanie z y-listą\n";
	Node *first1 = nullptr;
	Node *first2 = nullptr;
	Y_list *y_list = create_y_list();
	print_list(y_list->branch1);
	print_list(y_list->branch2);
	cout << zadanie2016B(y_list, first1, first2) << endl;
	print_list(first1);
	print_list(first2);
	assert(assert_zadanie2016B(first1, first2));
	cout << endl;

	cout << "trzecie zadanie:\n";
	Node *first3 = nullptr;
	Node *first4 = nullptr;
	create_sample_lists_zadanie2014B(first3, first4);
	print_list(first3);
	print_list(first4);
	zadanie2014B(first3, first4);
	print_list(first3);
	print_list(first4);
	cout << endl;

	cout << "Zadanie z jedynkami bitowymi:\n";
	Node *first5 = nullptr;
	add_at_end(first5, create_node(1024));
	add_at_end(first5, create_node(1023));
	add_at_end(first5, create_node(2023));
	for (int i = 0; i < 10; i++) {
		add_at_end(first5, create_node(i));
	}
	print_list(first5);
	zadanie2011(first5);
	print_list(first5);

	return 0;
}
