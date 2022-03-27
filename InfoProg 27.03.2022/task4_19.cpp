#include <iostream>
#include <string>

using namespace std;

struct queue {
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x) {
	queue* r = new queue;

	r->inf = x;
	r->next = nullptr;
	if (!h && !t) 
		h = t = r;
	else {
		t->next = r;
		t = r;
	}
}

int pop(queue*& h, queue*& t) {
	int i = h->inf;
	queue* r = h;
	h = h->next;
	if (!h)
		t = nullptr;
	delete r;
	return i;
}

int Max(queue*& h, queue*& t) {
	int max = pop(h, t);
	queue* res_h = nullptr;
	queue* res_t = nullptr;
	push(res_h, res_t, max);

	while (h) {
		int a = pop(h, t);
		if (a > max)
			max = a;
		push(res_h, res_t, a);
	}

	h = res_h;
	t = res_t;

	return max;
}

void result(queue*& h, queue*& t, int max) {
	while (h->inf != max) 
		push(h, t, pop(h, t));
}

void print(queue*& h, queue*& t) {
	while (h)
		cout << pop(h, t) << " ";
}

int main() {
	queue* h = nullptr;
	queue* t = nullptr;
	
	int n = 0; cout << "Input n = "; cin >> n;
	int x = 0; cout << "Input " << n << " digits: ";
	for (int i = 0; i < n; ++i) {
		cin >> x;
		push(h, t, x);
	}

	result(h, t, Max(h, t));

	cout << "Result: "; print(h, t); cout << "\n";
	
	return 0;
}