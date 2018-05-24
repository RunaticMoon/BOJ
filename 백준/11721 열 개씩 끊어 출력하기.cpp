#include <iostream>
using namespace std;

int main() {
	char str[101];
	cin.getline(str, 101);

	for (int i = 0; str[i] != '\0'; ++i) {
		cout << str[i];

		if (9 == i % 10)
			cout << endl;
	}

	return 0;
}