#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, loop_number;
	string str, newstr;

	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> loop_number >> str;

		newstr = "";
		for (auto it = str.begin(); it != str.end(); ++it) {
			for (int i = 0; i < loop_number; ++i) {
				newstr += *it;
			}
		}

		cout << newstr << '\n';
	}

	return 0;
}