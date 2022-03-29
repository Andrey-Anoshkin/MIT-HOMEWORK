#pragma once

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
class Tree {
private:
	tree<Type>* tr = new tree<Type>;
	Type R = tr->inf;

public:
	Tree(){
		tr->parent = nullptr;
		tr->branches = {};
	}
	~Tree(){
		Clear();
	}


	void insert(tree<Type>*& node, Type x){
		tree<Type>* r = new tree<Type>;
		r->inf = x;
		r->parent = node;
		node->branches.push_back(r);
	}

	void preorder(){
		cout << "\t" << tr->inf << "\n";
		int n = tr->branches.size();
		for (int i = 0; i < n; ++i) {
			cout << tr->branches[i]->inf << "\t";
		}
		cout << "\n";
	}

	void Insert(){
		if (tr->inf == R){
			Type x; cout << "Input root value = "; cin >> x;
			tr->inf = x;
		}
		while (true) {
			cout << "-------------- Insert --------------\n";
			cout << "Commands: move <number of branch | -1 to move up> | insert <value>\n";
			preorder();
			string command = "";
			Type value;
			int arg;

			cout << "Enter command: "; cin >> command;
			if (command == "move") {
				cin >> arg;
				if (arg == -1)
					if (!(tr->parent))
						cout << "Already at the top of the tree!\n";
					else
						tr = tr->parent;
				else
					if (arg <= tr->branches.size() && arg > 0)
						tr = tr->branches[arg - 1];
					else
						cout << "Incorrect branch!\n";
			}
			else
				if (command == "insert") {
					cin >> value;
					insert(tr, value);
					break;
				}
				else
					cout << "Incorrect command!\n";
		}
		while (tr->parent)
			tr = tr->parent;
	}

	void Delete() {
		if (tr->inf == R) {
			cout << "The tree is empty, nothing to delete!\n";
			return;
		}
		while (true) {
			cout << "-------------- Delete --------------\n";
			cout << "Commands: move <number of branch | -1 to move up> | delete <number of branch>\n";
			preorder();
			string command = "";
			int value;
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

	void Clear(bool flag = false) {
		clear(tr, flag);
	}

	void clear(tree<Type>*& node, bool flag = false) {
		int n = node->branches.size();
		for (int i = 0; i < n; ++i)
			clear(node->branches[i]);
		delete node;
		if (flag) {
			tree<Type>* r = new tree<Type>;
			r->parent = nullptr;
			r->branches = {};
			Type R = r->inf;
			node = r;
		}
	}

	bool finding(tree<Type>*& node, Type x) {
		if (node->inf == x)
			return true;
		int n = node->branches.size();
		for (int i = 0; i < n; ++i)
			if (finding(node->branches[i], x))
				return true;

		return false;
	}

	void IsContains() {
		if (tr->inf == R) {
			cout << "Tree is empty!\n";
			return;
		}
		Type x; cout << "Input element = "; cin >> x;

		if (finding(tr, x))
			cout << "Found " << x << "!\n\n";
		else
			cout << "No such element in the tree!\n\n";
	}

	void IsEmpty() {
		if (tr->inf == R)
			cout << "The tree is empty!\n\n";
		else
			cout << "The tree isn\'t empty!\n\n";
	}

	void Show() {
		if (tr->inf == R) {
			cout << "Tree is empty, nothing to show!\n";
			return;
		}
		while (true) {
			cout << "-------------- Tree --------------\n";
			cout << "Commands: move <number of branch | -1 to move up> | exit\n";
			preorder();
			string command = "";
			int value;
			cout << "Enter command: "; cin >> command;

			if (command == "move") {
				cin >> value;
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
				if (command == "exit")
					break;
				else
					cout << "Incorrect command!\n";
		}
		while (tr->parent)
			tr = tr->parent;
	}
};

