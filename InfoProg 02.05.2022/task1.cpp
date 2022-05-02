#include <iostream>

using namespace std;

struct tree {
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

void inorder(tree* tr) {
	if (tr) {
		inorder(tr->left);
		cout << tr->inf << " ";
		inorder(tr->right);
	}
}

tree* node(int x) {
	tree* r = new tree;
	r->inf = x;
	r->right = r->left = r->parent = nullptr;
	return r;
}

void insert(tree*& tr, int x) {
	tree* n = node(x);
	if (!tr) 
		tr = n; 
	else {
		tree * y = tr;
		while (y) {
			if (n->inf > y->inf) 
				if (y->right)
					y = y->right;
				else {
					n->parent = y; 
					y->right = n;
					break;
				}
			else if (n->inf < y->inf)
				if (y->left)
					y = y->left;
				else {
					n->parent = y;
					y->left = n;
					break;
				}
		}
	}
}

int Quantity(tree* tr) {
	if (tr)
		return Quantity(tr->left) + Quantity(tr->right) + (tr->left && !tr->right);
	else
		return 0;
}

int main() {
	tree* root = nullptr;
	int n = 0; cout << "Input n = "; cin >> n;
	cout << "Input tree: ";
	for (int i = 0; i < n; ++i) {
		int x = 0; cin >> x;
		insert(root, x);
	}

	cout << "Tree: "; inorder(root); cout << "\n";

	int quantity = Quantity(root);

	cout << "Quantity = " << quantity << "\n";

	return 0;
}