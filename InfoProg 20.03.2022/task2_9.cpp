#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void sorting(vector<int>& vec, int n, int f) {
	int gap = n / 1.247;
	while (gap >= 1) {
		if (gap < 1)
			gap = 1;

		for (int i = 0; i < n - gap; ++i)
			if (f * vec[i] > f * vec[i + gap])
				swap(vec[i], vec[i + gap]);

		gap /= 1.247;
	}
}

int main() {
	vector<int> v0;
	while (in.peek() != EOF) {
		int a = 0; in >> a; v0.push_back(a);
	}
	int n = sqrt(v0.size());
	vector<vector<int>> vec; vec.resize(n); for (int i = 0; i < n; vec[i].resize(n), ++i);
	for (int i = 0; i < v0.size(); ++i)
		vec[i % n][i / n] = v0[i];
	for (int i = 0; i < n; ++i)
		sorting(vec[i], n, (i % 3) ? 1 : -1);

	for (int i = 0; i < n; out << "\n", ++i)
		for (int j = 0; j < n; out << vec[j][i] << " ", ++j);
}