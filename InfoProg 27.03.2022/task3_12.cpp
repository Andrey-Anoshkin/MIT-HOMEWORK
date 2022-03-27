#include <iostream>
#include <string>

using namespace std;

struct queue {
	string inf;
	queue* next;
};

void push(queue*& h, queue*& t, string x) {
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

string pop(queue*& h, queue*& t) {
	string i = h->inf;
	queue* r = h;
	h = h->next;
	if (!h)
		t = nullptr;
	delete r;
	return i;
}

void result(queue*& h, queue*& t, string x) {
	queue* res_h = nullptr;
	queue* res_t = nullptr;

	while (h) {
		string a = pop(h, t);
		if (a != x)
			push(res_h, res_t, a);
		
	}

	h = res_h;
	t = res_t;
}

void print(queue*& h, queue*& t) {
	while (h)
		cout << pop(h, t) << " ";
}

int main() {
	queue* h = nullptr;
	queue* t = nullptr;
	
	int n = 0; cout << "Input n = "; cin >> n;
	string x = ""; cout << "Input " << n << " words: ";
	for (int i = 0; i < n; ++i) {
		cin >> x;
		push(h, t, x);
	}

	result(h, t, x);

	cout << "Result: "; print(h, t); cout << "\n";
	
	return 0;
}