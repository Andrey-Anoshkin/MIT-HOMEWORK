#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

ifstream in("input.txt");

struct People {
	string name, duty, date;
	int stage, salary;
};

struct list {
	People inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, People x) {
	list* r = new list;
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

void print(list* h, list* t) {
	list* p = h;
	while (p) {
		cout << p->inf.salary << " ";
		p = p->next;
	}
}

list* find(list* h, list* t, int x) {
	list* p = h;
	while (p) {
		if (p->inf.salary == x)
			break;
		p = p->next;
	}
	return p;
}

void del_node(list*& h, list*& t, list* r) {
	if (r == h && r == t)
		h = t = nullptr;
	else if (r == h) {
		h = h->next;
		h->prev = nullptr;
	}
	else if (r == t) {
		t = t->prev;
		t->next = nullptr;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}

void add(vector<pair<list*, list*>>& hash, vector<People>& base) {
	string x = ""; cout << "Input person to add: "; getline(cin, x);
	istringstream input(x);

	People r;
	input >> r.name >> r.duty >> r.date >> r.stage >> r.salary;
	base.push_back(r);

	push(hash[r.salary % hash.size()].first, hash[r.salary % hash.size()].second, r);

	cout << "Hash table:\n";
	for (int i = 0; i < hash.size(); cout << "\n", ++i) {
		cout << i << ": "; print(hash[i].first, hash[i].second);
	}
}

list* search(vector<pair<list*, list*>>& hash, int x) {
	return find(hash[x % hash.size()].first, hash[x % hash.size()].second, x);
}

void rem(vector<pair<list*, list*>>& hash) {
	int x = 0; cout << "Input salary to remove: "; cin >> x;

	list* r = search(hash, x);
	if (r)
		del_node(hash[r->inf.salary % hash.size()].first, hash[r->inf.salary % hash.size()].second, r);
	else
		cout << "Salary " << x << " doesn't exist!\n";

	cout << "Hash table:\n";
	for (int i = 0; i < hash.size(); cout << "\n", ++i) {
		cout << i << ": "; print(hash[i].first, hash[i].second);
	}
}

void _run() {
	string str = "";
	vector<People> base;

	for (int i = 0; in.peek() != EOF; ++i) {
		base.resize(i + 1);
		getline(in, str);
		istringstream input(str);
		input >> base[i].name >> base[i].duty >> base[i].date >> base[i].stage >> base[i].salary;
	}

	int m = 0; cout << "Input M = "; cin >> m;
	vector<pair<list*, list*>> hash; hash.resize(m);
	for (int i = 0; i < m; ++i)
		hash[i].first = hash[i].second = nullptr;

	getline(cin, str);

	for (int i = 0; i < base.size(); ++i)
		push(hash[base[i].salary % m].first, hash[base[i].salary % m].second, base[i]);

	cout << "Hash table:\n";
	for (int i = 0; i < hash.size(); cout << "\n", ++i) {
		cout << i << ": "; print(hash[i].first, hash[i].second);
	}

	add(hash, base);

	int x = 0; cout << "Input salary to search: "; cin >> x;

	list* r = search(hash, x);
	if (r)
		cout << "Found " << r->inf.name << " " << r->inf.duty << " " << r->inf.date << " " << r->inf.stage << " " << r->inf.salary << "!\n";
	else
		cout << "Person with salary " << x << " doesn't exist!\n";

	rem(hash);
}

int main() {
	_run();

	return 0;
}