#include "tree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


template<class Type>
struct queue {
	Type inf;
	queue* next;
};

template<class Type>
struct tree {
	Type inf;
	tree<Type>* parent;
	queue<tree<Type>*>* head;
	queue<tree<Type>*>* tail;
};

template<class Type>
void push(queue<Type>*& h, queue<Type>*& t, Type x) {
	queue<Type>* r = new queue<Type>;
	r->inf = x;
	r->next = nullptr;
	if (!h && !t)
		h = t = r;
	else {
		t->next = r;
		t = r;
	}
}

template<class Type>
Type pop(queue<Type>*& h, queue<Type>*& t) {
	queue<Type>* r = h;
	Type i = h->inf;
	h = h->next;
	if (!h)
		t = nullptr;

	delete r;
	return i;
}

template<class Type>
void insert(tree<Type>*& node, Type x) {
	tree<Type>* r = new tree<Type>;
	r->head = nullptr;
	r->tail = nullptr;
	r->inf = x;
	r->parent = node;
	push(node->head, node->tail, r);
}

template<class Type>
void preorder(tree<Type>* tr, bool flag = false) {
	if (flag)
		cout << tr->inf << " ";
	while (tr->head)
		preorder(pop(tr->head, tr->tail), true);
}

template<class Type>
void Insert(tree<Type>*& tr) {
	return;
}

int main() {
	tree<int>* root = new tree<int>;
	root->parent = nullptr;
	root->head = nullptr;
	root->tail = nullptr;
	insert(root, 5);
	insert(root, 4);
	insert(root->head->inf, 3);

	tree<int>* root_copy = new tree<int>;
	root_copy = root;
	
	preorder(root_copy); cout << "\n";
	
	root_copy = root;

	preorder(root_copy); cout << "\n";

	return 0;
}