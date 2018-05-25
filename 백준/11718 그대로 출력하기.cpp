#include <iostream>
#include <string>
using namespace std;

int main() {
	string array[100];
	char str[100];
	for (auto i = 0; i < 100; i++) {
		getline(cin, array[i], '\n');
	}
	for (auto i = 0; i < 100; i++) {
		cout << array[i] << endl;
	}

	return 0;
}