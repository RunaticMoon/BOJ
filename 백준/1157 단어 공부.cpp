#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int compare(int a, int b) {
	return a - b;
}

int main() {
	string str;
	int alphabet[26], tempAlphabet[26], max = 0;
	fill(alphabet, alphabet + 26, 0);

	cin >> str;

	for (auto it = str.begin(); it != str.end(); ++it) {
		if (*it >= 'a')
			++alphabet[*it - 'a'];
		else
			++alphabet[*it - 'A'];
	}

	for (int i = 0; i < 26; ++i) {
		tempAlphabet[i] = alphabet[i];
	}

	sort(tempAlphabet, tempAlphabet + 26, greater<int>());
	max = tempAlphabet[0];

	if (tempAlphabet[0] == tempAlphabet[1])
		cout << "?";
	else {
		for (int i = 0; i < 26; ++i) {
			if (alphabet[i] == max)
				cout << (char)('A' + i);
		}
	}

	return 0;
}