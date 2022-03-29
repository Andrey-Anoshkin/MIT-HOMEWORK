#include "tree.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	Tree<string> root;
	int option = 0;
	while (true) {
		bool stop = false;
		cout << "\n-------------------------\n";
		cout << "1. Insert\n2. Delete\n3. Clear\n4. IsContains\n5. isEmpty\n6. Show\n7. Exit\n-------------------------\n\nChoose the option: "; cin >> option; cout << "\n";
		switch (option) {
		case 1: root.Insert(); break;
		case 2: root.Delete(); break;
		case 3: root.Clear(true); break;
		case 4: root.IsContains(); break;
		case 5: root.IsEmpty(); break;
		case 6: root.Show(); break;
		default: stop = true; break;
		}
		if (stop)
			break;
	}

	return 0;
}