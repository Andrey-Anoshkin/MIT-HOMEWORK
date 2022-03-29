#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<class Type>
struct tree {
	Type inf;
	tree<Type>* parent;
	vector<tree<Type>*> branches;
};

template<class Type>
void insert(tree<Type>*& node, Type x) {
	tree<Type>* r = new tree<Type>;
	r->inf = x;
	r->parent = node;
	node->branches.push_back(r);
}

template<class Type>
void preorder(tree<Type>* tr) {
	cout << "\t" << tr->inf << "\n";
	int n = tr->branches.size();
	for (int i = 0; i < n; ++i) {
		cout << tr->branches[i]->inf << "\t";
	}
	cout << "\n";
}

template<class Type>
void Insert(tree<Type>*& tr, Type R) {
	if (tr->inf == R) {
		int x = 0; cout << "Input root value = "; cin >> x;
		tr->inf = x;
	}
	while (true) {
		cout << "-------------- Insert --------------\n";
		cout << "Commands: move <number of branch | -1 to move up> | insert <value>\n";
		preorder(tr);
		string command = "";
		Type value;
		cout << "Enter command: "; cin >> command >> value;

		if (command == "move") {
			if (value == -1)
				if (!(tr->parent))
					cout << "Already at the top of the tree!\n";
				else
					tr = tr->parent;
			else
				if (value <= tr->branches.size() && value > 0)
					tr = tr->branches[value - 1];
				else
					cout << "Incorrect branch!\n";
		}
		else
			if (command == "insert") {
				insert(tr, value);
				break;
			}
			else
				cout << "Incorrect command!\n";
	}
	while (tr->parent)
		tr = tr->parent;
}

template<class Type>
void Delete(tree<Type>*& tr, Type R) {
	if (tr->inf == R) {
		cout << "The tree is empty, nothing to delete!\n";
		return;
	}
	while (true) {
		cout << "-------------- Delete --------------\n";
		cout << "Commands: move <number of branch | -1 to move up> | delete <number of branch>\n";
		preorder(tr);
		string command = "";
		Type value;
		cout << "Enter command: "; cin >> command >> value;

		if (command == "move") {
			if (value == -1)
				if (!(tr->parent))
					cout << "Already at the top of the tree!\n";
				else
					tr = tr->parent;
			else
				if (value <= tr->branches.size() && value > 0)
					tr = tr->branches[value - 1];
				else
					cout << "Incorrect branch!\n";
		}
		else
			if (command == "delete")
				if (value <= tr->branches.size() && value > 0) {
					swap(tr->branches[value - 1], tr->branches[tr->branches.size() - 1]);
					tr->branches.pop_back();
					break;
				}

				else
					cout << "Incorrect branch!\n";
			else
				cout << "Incorrect command!\n";
	}
	while (tr->parent)
		tr = tr->parent;
}

template<class Type>
void Clear(tree<Type>*& tr) {
	tree<Type>* root = new tree<Type>;
	root->parent = nullptr;
	root->branches = {};
	tr = root;
	cout << "The tree successfully cleared!\n";
}

template<class Type>
bool finding(tree<Type>*& tr, Type x) {
	if (tr->inf == x)
		return true;
	int n = tr->branches.size();
	for (int i = 0; i < n; ++i)
		if (finding(tr->branches[i], x))
			return true;

	return false;
}

template<class Type>
void IsContains(tree<Type>*& tr, Type R) {
	if (tr->inf == R) {
		cout << "Tree is empty!\n";
		return;
	}
	int x = 0; cout << "Input element = "; cin >> x;

	if (finding(tr, x))
		cout << "Found " << x << "!\n\n";
	else
		cout << "No such element in the tree!\n\n";
}

template<class Type>
void IsEmpty(tree<Type>*& tr, Type R) {
	if (tr->inf == R)
		cout << "The tree is empty!\n\n";
	else
		cout << "The tree isn\'t empty!\n\n";
}

template<class Type>
Type null_element(tree<Type>*& tr) {
	return tr->inf;
}

int main() {
	tree<int>* root = new tree<int>;
	root->parent = nullptr;
	root->branches = {};
	int R = null_element(root);
	int option = 0;
	while (true) {
		bool stop = false;
		cout << "\n-------------------------\n";
		cout << "1. Insert\n2. Delete\n3. Clear\n4. IsContains\n5. isEmpty\n6. Exit\n-------------------------\n\nChoose the option: "; cin >> option; cout << "\n";
		switch (option) {
		case 1: Insert(root, R); break;
		case 2: Delete(root, R); break;
		case 3: Clear(root); break;
		case 4: IsContains(root, R); break;
		case 5: IsEmpty(root, R); break;
		default: stop = true; break;
		}
		if (stop)
			break;
	}

	return 0;
}