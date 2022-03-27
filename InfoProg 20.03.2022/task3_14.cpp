#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void sorting(vector<int>& vec, int n) {
	for (int i = 0; i < n; ++i) {
		vector<int>::iterator Min_it = min_element(vec.begin() + i, vec.end());
		int Min = *Min_it;
		*Min_it = vec[i];
		vec[i] = Min;
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
		vec[i / n][i % n] = v0[i];
	
	for (int i = n - 2; i >= 0; --i) {
		vector<vector<int>> array; array.resize(2);
		for (int j = 0; i + j < n; ++j) {
			array[0].push_back(vec[i + j][j]);
			array[1].push_back(vec[j][i + j]);
		}
		
		sorting(array[0], array[0].size());
		sorting(array[1], array[1].size());

		for (int j = 0; i + j < n; ++j) {
			vec[i + j][j] = array[0][j];
			vec[j][i + j] = array[1][j];
		}
	}


	for (int i = 0; i < n; out << "\n", ++i)
		for (int j = 0; j < n; out << vec[i][j] << " ", ++j);
}