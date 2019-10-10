#include <iostream>
#include <cmath>
using namespace std;

int N;

void func(int a, int b, int n) {
	int s = a ^ b;

	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	func(a, s, n - 1);
	cout << a << ' ' << b << '\n';
	func(s, b, n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << (long long)(pow(2, N) - 1) << '\n';
	func(1, 3, N);

	return 0;
}