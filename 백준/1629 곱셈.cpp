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

	/*
		sum = 1;

		while (b > 0) {
			if (b % 2 != 0) {
				sum *= a;
				sum %= c;
			}
			a *= a;
			a %= c;
			b /= 2;
		}
	*/

	cout << mul(a, b, c);

	return 0;
}