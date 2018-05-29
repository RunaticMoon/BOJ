#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	string str;
	int score, num;

	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> str;

		score = 0;
		num = 0;
		for (auto it = str.begin(); it != str.end(); ++it) {
			if (*it == 'O') {
				++num;
				score += num;
			}
			else if (*it == 'X')
				num = 0;
		}

		cout << score << '\n';
	}

	return 0;
}