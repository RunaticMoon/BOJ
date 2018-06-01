#include <iostream>
using namespace std;

long long mul(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 1) {
		return (mul(a, b - 1, c) * a) % c;
	}
	else {
		long long half = mul(a, b / 2, c) % c;
		return (half * half) % c;
	}
}

int main() {
	long long a, b, c;

	cin >> a >> b >> c;

	cout << mul(a, b, c);

	return 0;
}