#include <iostream>
#include <string>
using namespace std;

int main() {
	int num = 0;
	bool flag = true;
	string str;
	getline(cin, str, '\n');

	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it != ' ' && flag) {
			flag = false;
			++num;
		}
		else if (*it == ' ' && !flag)
			flag = true;
	}

	cout << num;

	return 0;
}