#include <iostream>

using namespace std;

struct queue {
	int inf;
	queue* next;
};

struct stack {
	int inf;
	stack* next;
};

struct list {
	int inf;
	list* inf_h;
	list* inf_t;
	list* next;
	list* prev;
};

void push_queue(queue*& h, queue*& t, int x) {
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

int pop_queue(queue*& h, queue*& t) {
	queue* r = h;
	int i = h->inf; 
	h = h->next; 
	if (!h) 
		t = nullptr;
	delete r; 
	return i;
}

void push_stack(stack*& h, int x) {
	stack* r = new stack; 
	r->inf = x; 
	r->next = h; 
	h = r;
}

int pop_stack(stack*& h) {
	int i = h->inf; 
	stack * r = h; 
	h = h->next; 
	delete r; 
	return i;
}

void push_list(list*& h, list*& t, list* x_h, list* x_t, int x) { 
	list * r = new list; 
	r->inf_h = x_h;
	r->inf_t = x_t;
	r->inf = x;
	r->next = nullptr; 
	if (!h && !t) { 
		r->prev = nullptr; 
		h = r; 
	}
	else {
		t->next = r; 
		r->prev = t; 
	}
	t = r; 
}

void print_list(list* h, list* t) { 
	list * p = h; 
	while (p) { 
		cout << p->inf << " ";
		p = p->next;
	}
}

void depth(list*** array, int x, int n, int* arr) {
	stack* h = nullptr;

	arr[x] = 1;
	push_stack(h, x);
	cout << x << " ";

	

	while (h) {
		bool fl = false;
		int r = h->inf;
		int y = 0;
		for (list* i = array[r][0]; i; i = i->next)
			if (!arr[i->inf]) {
				y = i->inf;
				fl = true;
				break;
			}
		if (fl) {
			arr[y] = 1;
			push_stack(h, y);
			cout << y << " ";
		}
		else
			pop_stack(h);
	}
	for (int i = 0; i < n; ++i)
		if (!arr[i])
			depth(array, i, n, arr);
}

void width(list*** array, int x, int n, int* arr) {
	queue* h = nullptr;
	queue* t = nullptr;

	arr[x] = 1;
	push_queue(h, t, x);
	cout << x << " ";

	while (h) {
		int r = pop_queue(h, t);
		int y = 0;
		for (list* i = array[r][0]; i; i = i->next)
			if (!arr[i->inf]) {
				y = i->inf;
				arr[y] = 1;
				push_queue(h, t, y);
				cout << y << " ";
			}
	}
	for (int i = 0; i < n; ++i)
		if (!arr[i])
			width(array, i, n, arr);
}

int main() {
	int n = 0; cout << "Input n = "; cin >> n;
	list*** array = new list** [n];
	for (int i = 0; i < n; array[i] = new list* [2], ++i);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 2; array[i][j] = nullptr, ++j);

	bool** matrix = new bool* [n];
	for (int i = 0; i < n; matrix[i] = new bool[n], ++i);

	bool x = 0; cout << "Input matrix:\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; cin >> x, matrix[i][j] = x, ++j);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			if (matrix[i][j]) 
				push_list(array[i][0], array[i][1], array[j][0], array[j][1], j);

	/*cout << "\n";

	for (int i = 0; i < n; ++i, cout << "\n")
		print_list(array[i][0], array[i][1]);

	cout << "\n";*/

	int* dep = new int[n];
	for (int i = 0; i < n; ++i)
		dep[i] = 0;

	cout << "\n";
	depth(array, 0, n, dep);
	cout << "\n";
	
	int* wide = new int[n];
	for (int i = 0; i < n; ++i)
		wide[i] = 0;

	cout << "\n";
	width(array, 0, n, wide);
	cout << "\n";
	
	return 0;
}

/*
0 1 1 0 1 1 0
1 0 0 1 0 0 0
1 0 0 0 0 1 0
0 1 0 0 0 0 0
1 0 0 0 0 0 1
1 0 1 0 0 0 1
0 0 0 0 1 1 0
*/