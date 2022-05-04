#include <iostream>
#include <string>

using namespace std;

struct tree {
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

struct queue {
	tree* inf;
	queue* next;
};

void push(queue*& h, queue*& t, tree* x) { 
	queue* r = new queue; 
	r->inf = x;
	r->next = nullptr; 
	if (!h && !t) 
		h = t = r; 
	else {
		t->next = r; 
		t = r; 
	}
}

tree* pop(queue*& h, queue*& t) { 
	queue* r = h; 
	tree* i = h->inf;
	h = h->next;
	if (!h)
		t = nullptr;
	delete r;
	return i;
}

void preorder(tree* tr) {
	if (tr) {
		cout << tr->inf << " ";
		preorder(tr->left);
		preorder(tr->right);
	}
}

tree* node(int x) {
	tree* r = new tree;
	r->inf = x;
	r->right = r->left = r->parent = nullptr;
	return r;
}

void create(tree*& tr, int n) {
	int x = 0;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}

void width_tracing(tree* tr, int n) {
	queue* h = nullptr;
	queue* t = nullptr;
	int k = 0, k2 = 1;
	push(h, t, tr);
	cout << tr->inf;
	int depth = pow(2, n);

	while (h) {
		k++;
		if (k == k2) {
			cout << "\n";
			k2 *= 2;
		}
		if (k2 >= depth)
			break;
		tree* r = pop(h, t);
		
		if (r) {
			push(h, t, r->left);
			push(h, t, r->right);
		}
		

		if (r) {
			if (r->left)
				cout << r->left->inf << "\t";
			else
				cout << "NULL\t";
			if (r->right)
				cout << r->right->inf << "\t";
			else
				cout << "NULL\t";
		}
		else
			cout << "NULL\tNULL\t";
	}
}

int main() {
	tree* root = nullptr;
	int n = 0; cout << "Input n = "; cin >> n;
	cout << "Input tree: "; create(root, n);
	
	cout << "Tree: "; preorder(root); cout << "\n";
	
	int depth = 0;
	for (int i = n; i > 0; i /= 2, ++depth);

	cout << "Tree:\n"; width_tracing(root, depth);

	return 0;
}

/*
8 5 3 7 4 2 1 6 9
*/