#include <iostream>
using namespace std;

int main() {
	int n, sum, temp;

	cin >> n;

	for (int i = 1; i <= 1000000; ++i) {
		temp = i;
		sum = temp;

		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n) {
			cout << i;
			return 0;
		}
	}

	cout << "0";

	return 0;
}