#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

vector<int> order;
vector<int> path;

void dfs1(vector<vector<int>>& Gr, int x, bool* used) {
	used[x] = 1;
	for (int i = 0; i < Gr[x].size(); ++i)
		if (!used[Gr[x][i]])
			dfs1(Gr, Gr[x][i], used);
	order.push_back(x);
}

void dfs2(vector<vector<int>>& Gr, int x, bool* used) {
	used[x] = 1;
	path.push_back(x);
	for (int i = 0; i < Gr[x].size(); ++i)
		if (!used[Gr[x][i]])
			dfs2(Gr, Gr[x][i], used);
}

void search(vector<vector<int>>& Gr, vector<vector<int>>& GrT, int n) {
	bool* used = new bool[n];
	for (int i = 0; i < n; used[i] = 0, ++i);

	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(Gr, i, used);

	for (int i = 0; i < n; used[i] = 0, ++i);

	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(GrT, v, used);
			sort(path.begin(), path.end());
			for (vector<int>::iterator it = path.begin(); it != path.end(); cout << *it << " ", ++it);
			cout << "\n";
			path.clear();
		}
	}
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

	vector<vector<int>> GraphT;
	GraphT.resize(n);
	for (int i = 0; i < n; ++i)
		for (vector<int>::iterator it = Graph[i].begin(); it != Graph[i].end(); ++it)
			GraphT[*it].push_back(i);

	for (int i = 0; i < n; ++i)
		sort(GraphT[i].begin(), GraphT[i].end());

	search(Graph, GraphT, n);
}

int main() {
	_run();

	return 0;
}

/*
1
2 4 5
3
2 7
0 5
6
5
3 6
*/