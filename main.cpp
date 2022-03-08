#include <iostream>

int fib(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

int main() {
	std::cout << "Hello, World!\n";

	int n = 0; std::cout << "Input n = "; std::cin >> n; 
	std::cout << fib(n) << "\n";

	return 0;
}