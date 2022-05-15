#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int quantity(vector<vector<int>> Gr, int x) {
	int ans = 0;
	for (int i = 0; i < Gr.size(); ++i)
		if (i == x)
			ans += Gr[x].size();
		else
			if (find(Gr[i].begin(), Gr[i].end(), x) != Gr[i].end() && find(Gr[x].begin(), Gr[x].end(), i) == Gr[x].end())
				ans += 1;

	return ans;
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

	int x = 0; cout << "Input node number: "; cin >> x;
	int ans = quantity(Graph, x);
	cout << "Answer: " << ans << "\n";
}

int main() {
	_run();

	return 0;
}