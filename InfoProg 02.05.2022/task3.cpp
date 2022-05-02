#include <iostream>
#include <string>

using namespace std;

struct tree {
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

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

void leaves_finder(tree* tr) {
	if (!tr->left && !tr->right) {
		cout << tr->inf << " ";
		return;
	}
	if (tr->left)
		leaves_finder(tr->left);
	if (tr->right)
		leaves_finder(tr->right);
}

int main() {
	tree* root = nullptr;
	int n = 0; cout << "Input n = "; cin >> n;
	cout << "Input tree: "; create(root, n);
	
	cout << "Tree: "; preorder(root); cout << "\n";
	
	cout << "Leaves: "; leaves_finder(root); cout << "\n";

	return 0;
}