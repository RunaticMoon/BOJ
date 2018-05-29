#include <iostream>
#include <string>
using namespace std;

int main() {
	string dial[8] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	string str;
	int sum = 0;

	cin >> str;

	for (auto &i : str) {
		for (int j = 0; j < 8; ++j) {
			if (dial[j].find(i) != string::npos) {
				sum += j + 3;
				break;
			}
		}
	}

	cout << sum << endl;

	return 0;
}