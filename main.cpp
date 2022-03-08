#include <iostream>

void fib(int n) {
	int a = 0, b = 1;

	for (int i = 0; i < n; ++i) {
		std::cout << a << "\n";

		int t = b;
		b += a;
		a = t;
	}
}

int main() {
	std::cout << "Hello, World!\n";

	int n = 0; std::cout << "Input n = "; std::cin >> n; 
	fib(n);

	return 0;
}