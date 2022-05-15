#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

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

	for (int i = 0; i < n; cout << "\n", ++i)
		cout << "Node " << i << " outcome degree: " << Graph[i].size();
}

int main() {
	_run();

	return 0;
}