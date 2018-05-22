#include <iostream>
#include <vector>
using namespace std;

int main() {
	int array_number, num, n;
	vector<int> array;

	cin >> array_number >> num;

	for (int i = 0; i < array_number; ++i) {
		cin >> n;
		array.push_back(n);
	}

	for (auto i : array) {
		if (i < num)
			cout << i << ' ';
	}

	return 0;
}