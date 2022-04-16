#include <iostream>
#include <cmath>

using namespace std;

void Mult(float** array_1, int n1, int m1, float** array_2, int n2, int m2) {
	if (m1 != n2)
		return;

	int n = n1, m = m2;

	float** array = new float* [n];
	for (int i = 0; i < n; array[i] = new float[m], ++i);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; array[i][j] = 0, ++j);

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			for (int k = 0; k < n2; ++k)
				array[i][j] += array_1[i][k] * array_2[k][j];
	
	cout << "New matrix:\n";
	for (int i = 0; i < n; cout << "\n", ++i)
		for (int j = 0; j < m; cout << array[i][j] << " ", ++j);
}

int main() {
	int n1 = 0, m1 = 0; cout << "Input n1, m1: "; cin >> n1 >> m1;
	float** array_1 = new float* [n1];
	for (int i = 0; i < n1; array_1[i] = new float[m1], ++i);
	cout << "Input matrix 1:\n";
	float element = 0;
	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < m1; ++j) {
			cin >> element;
			array_1[i][j] = element;
		}
	cout << "\n";

	int n2 = 0, m2 = 0; cout << "Input n2, m2: "; cin >> n2 >> m2;
	float** array_2 = new float* [n2];
	for (int i = 0; i < n2; array_2[i] = new float[m2], ++i);
	cout << "Input matrix 2:\n";
	for (int i = 0; i < n2; ++i)
		for (int j = 0; j < m2; ++j) {
			cin >> element;
			array_2[i][j] = element;
		}
	cout << "\n";

	Mult(array_1, n1, m1, array_2, n2, m2);
}