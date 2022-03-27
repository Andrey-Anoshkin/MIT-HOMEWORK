#include <iostream>
#include <string>

using namespace std;

struct stack {
	string inf;
	stack* next;
};

void push(stack*& h, string x) {
	stack* r = new stack;

	r->inf = x;
	r->next = h;
	h = r;
}

string pop(stack*& h) {
	string i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h) {
	stack* new_head = nullptr;
	while (h)
		push(new_head, pop(h));
	h = new_head;
}

int main() {
	stack* h = nullptr;
	stack* h1 = nullptr;
	int n = 0; cout << "Input n = "; cin >> n;
	
	string str = ""; cout << "Input " << n << " words: ";
	for (int i = 0; i < n; ++i) {
		cin >> str; push(h, str);
	}
	char x; cout << "Input letter = "; cin >> x;
	while (h) {
		string str1 = pop(h);
		if (str1[str1.length() - 1] != x)
			push(h1, str1);
	}

	cout << "Result: ";

	while (h1)
		cout << pop(h1) << " ";

	cout << "\n";
	return 0;
}