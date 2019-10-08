#include <iostream>
using namespace std;

int a, b, n, sum, mul;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	mul = 1;
	while (b != 0) {
		n = b % 10;
		b /= 10;

		sum += a * n * mul;
		mul *= 10;

		cout << a * n << endl;
	}

	cout << sum;

	return 0;
}