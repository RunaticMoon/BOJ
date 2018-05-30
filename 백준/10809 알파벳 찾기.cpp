#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
	string str;
	array<int, 26> arr;
	int num, n;
	fill(arr.begin(), arr.end(), -1);

	cin >> str;

	n = 0;
	for (auto it = str.begin(); it != str.end(); ++it, ++n) {
		num = *it - 'a';

		if (arr[num] == -1)
			arr[num] = n;
	}

	for (auto n : arr) {
		cout << n << ' ';
	}

	return 0;
}