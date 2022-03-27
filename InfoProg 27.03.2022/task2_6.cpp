#include <iostream>
#include <string>

using namespace std;

struct stack {
	int inf;
	stack* next;
};

void push(stack*& h, int x) {
	stack* r = new stack;

	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h) {
	int i = h->inf;
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

void result(stack*& h, int Max) {
	stack* res = nullptr;

	while (h) {
		int a = pop(h);
		if (a != Max)
			push(res, a);
	}

	h = res;
}

int max(stack*& h) {
	stack* h1 = nullptr;
	int Max = pop(h);
	push(h1, Max);

	while (h) {
		int i = pop(h);
		if (i >= Max)
			Max = i;
		push(h1, i);
	}

	reverse(h1);
	h = h1;

	return Max;
}

void print(stack*& h) {
	while (h)
		cout << pop(h) << " ";
}

int main() {
	stack* h = nullptr;
	
	int n = 0; cout << "Input n = "; cin >> n;
	int x = 0; cout << "Input " << n << " elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> x;
		push(h, x);
	}

	result(h, max(h));

	cout << "Result: "; print(h); cout << "\n";
	
	return 0;
}