#include <iostream>
using namespace std;

int constructor(int n);

int main() {
	bool array[11000] = { false, };

	for (int i = 1; i < 10000; ++i) {
		array[constructor(i)] = true;
	}

	for (int i = 1; i <= 10000; ++i) {
		if (!array[i])
			cout << i << '\n';
	}

	return 0;
}

int constructor(int n) {
	int result = n;

	for (int i = 10000; i > 0; i /= 10) {
		result += n / i;
		n -= (n / i) * i;
	}

	return result;
}