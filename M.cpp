#include <iostream>
#include <cmath>

using namespace std;

float Gauss(float** array, int n) {
	for (int i = 0; i < n - 1; ++i) {
		float l = 0;
		for (int j = i + 1; j < n; ++j) {
			l = -array[j][i] / array[i][i];
			for (int k = 0; k < n; ++k) {
				array[j][k] += array[i][k] * l;
			}
		}
	}

	float ans = 1;

	for (int i = 0; i < n; ++i)
		ans *= array[i][i];

	return ans;
}

float GetDet(float** array, int n) {
	if (n == 1)
		return array[0][0];
	if (n == 2)
		return array[0][0] * array[1][1] - array[0][1] * array[1][0];

	float ans = 0;
	for (int k = 0; k < n; ++k) {
		float** mas = new float* [n - 1];
		for (int i = 0; i < n - 1; mas[i] = new float[n - 1], ++i);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j == k)
					continue;
				else
					if (j < k)
						mas[i - 1][j] = array[i][j];
					else
						mas[i - 1][j - 1] = array[i][j];
			}
		}

		ans += (1 - 2 * (k % 2)) * array[0][k] * GetDet(mas, n - 1);
	}
	
	return ans;
}

int main() {
	int n = 0, m = 0; cout << "Input n: "; cin >> n;

	float** array = new float*[n];

	for (int i = 0; i < n; array[i] = new float[n], ++i);

	float element = 0; cout << "Input array:\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> element;
			array[i][j] = element;
		}

	float d = 0;
	d = Gauss(array, n);
	//d = GetDet(array, n);

	cout << "Determinant = " << d << "\n";

	return 0;
}