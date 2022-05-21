#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> Gr, bool* used, vector<int>& order, int x) {
	used[x] = 1;
	for (int i = 0; i < Gr[x].size(); ++i) 
		if (!used[Gr[x][i]])
			dfs(Gr, used, order, Gr[x][i]);

	order.push_back(x);
}

void top_sort(vector<vector<int>> Graph, int n) {
	bool* used = new bool[n];
	for (int i = 0; i < n; used[i] = 0, ++i);
	vector<int> order;
	cout << "Topological sort: ";
	dfs(Graph, used, order, 0);
	for (int i = n - 1; i >= 0; --i)
		cout << order[i] << " ";
	cout << "\n";
}

void eiler(vector<vector<int>>& Gr, int n) {
	int v1 = -1;
	int v2 = -1;
	vector<int> res;
	vector<int> path;

	

	for (int i = 0; i < n; ++i) {
		if (Gr[i].size() % 2)
			if (v1 == -1)
				v1 = i;
			else
				if (v2 == -1)
					v2 = i;
				else {
					cout << "No cycle!\n";
				}
	}

	if (v1 != -1) {
		Gr[v1].push_back(v2);
		Gr[v2].push_back(v1);
		sort(Gr[v1].begin(), Gr[v1].end());
		sort(Gr[v2].begin(), Gr[v2].end());
	}

	stack<int> h;
	h.push(v1);
	while (!h.empty()) {
		int r = h.top();
		if (Gr[r].size()) {
			int x = Gr[r][0];
			h.push(x);

			
			swap(Gr[r][0], Gr[r][Gr[r].size() - 1]);
			Gr[r].pop_back();
			sort(Gr[r].begin(), Gr[r].end());

			for (int i = 0; i < Gr[x].size(); ++i) 
				if (Gr[x][i] == r) {
					swap(Gr[x][i], Gr[x][Gr[x].size() - 1]);
					Gr[x].pop_back();
					sort(Gr[x].begin(), Gr[x].end());
					break;
				}
		}
		else {
			h.pop();
			res.push_back(r);
		}
	}

	if (v1 != -1) 
		for (int i = 0; i + 1 < res.size(); ++i)
			if (res[i] == v1 && res[i + 1] == v2) {
				vector<int> res1;
				for (int j = i + 1; j < res.size(); ++j)
					res1.push_back(res[j]);
				for (int j = 1; j <= i; ++j)
					res1.push_back(res[j]);
				res = res1;
			}
	
		
	for (int i = 0; i < n; ++i)
		if (Gr[i].size()) {
			cout << "No cycle!\n";
			return;
		}

	cout << "Eiler cycle: ";
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
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

		sort(Graph[i].begin(), Graph[i].end());
		Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end());
	}

	top_sort(Graph, n);

	eiler(Graph, n);
}

int main() {
	_run();

	return 0;
}

/*
9

1 2
2 3 4
4 5
6
6
4 7
7 8
8



1 2 4 5
0 3 4
0 3 4
1 2 4 5
0 1 2 3
0 3

*/