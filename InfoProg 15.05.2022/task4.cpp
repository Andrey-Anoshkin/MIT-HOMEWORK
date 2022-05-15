#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

void depth_tracing(vector<vector<int>>& Gr, int x) {
	bool* used = new bool[Gr.size()];
	stack<int> h;
	for (int i = 0; i < Gr.size(); used[i] = 0, ++i);
	used[x] = 1;
	h.push(x);

	while (!h.empty()) {
		bool fl = false;
		int r = h.top();
		int y = 0;

		for (vector<int>::iterator it = Gr[r].begin(); it != Gr[r].end(); ++it)
			if (!used[*it]) {
				y = *it;
				fl = true;
				break;
			}

		if (fl) {
			used[y] = 1;
			h.push(y);
		}
		else
			h.pop();
	}

	cout << "Impossible to get to nodes: ";
	for (int i = 0; i < Gr.size(); ++i)
		if (!used[i])
			cout << i << " ";

	cout << "\n";
}

void _run() {
	int n = 0; cout << "Input quantity of graph's nodes = "; cin >> n;
	vector<vector<int>> Graph;
	Graph.resize(n);
	string str = ""; getline(cin, str);
	for (int i = 0; i < n; ++i) {
		cout << "Node " << i << ": "; getline(cin, str);
		istringstream in(str);
		int x = 0;
		while (in >> x)
			if (x < n)
				Graph[i].push_back(x);

		Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end());
	}

	int x = 0; cout << "Input node: "; cin >> x;
	depth_tracing(Graph, x);
}

int main() {
	_run();

	return 0;
}