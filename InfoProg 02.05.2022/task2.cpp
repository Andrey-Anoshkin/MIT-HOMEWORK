#include <iostream>
#include <string>

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

tree* find(tree* tr, int x) {
	tree* y = tr;
	while (y) {
		if (y->inf == x) {
			return y;
		}
		else
			if (y->inf < x)
				y = y->right;
			else
				y = y->left;
	}
	return nullptr;
}

string itos(int x) {
	string str = "";
	while (x) {
		str.insert(0, 1, (x % 10) + '0');
		x /= 10;
	}
	return str;
}

void path(tree* x) {
	string str = "";
	while (x) {
		str += itos(x->inf);
		x = x->parent;
	}
	for (string::size_type pos = str.length() - 1; pos < str.length(); --pos)
		cout << str[pos] << " ";
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
	
	int x = 0; cout << "Input X = "; cin >> x;
	tree* r = find(root, x);

	cout << "Path: "; path(r); cout << "\n";

	return 0;
}