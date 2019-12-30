#include <iostream>
using namespace std;

int a, b;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a%b);
}

int lcm(int a, int b) {
	int c = gcd(a, b);

	a /= c;
	b /= c;

	return a * b * c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	cout << gcd(a, b) << '\n' << lcm(a, b);

	return 0;
}