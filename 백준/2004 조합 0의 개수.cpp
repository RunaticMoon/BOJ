#include <iostream>
using namespace std;

long long n, m;
long long two, five;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	m = (m > n - m ? n - m : m);

	// n!
	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}

	// m!
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		five -= m / i;
	}

	// (n-m)!
	for (long long i = 2; i <= (n - m); i *= 2) {
		two -= (n - m) / i;
	}
	for (long long i = 5; i <= (n - m); i *= 5) {
		five -= (n - m) / i;
	}

	cout << (two > five ? five : two);

	return 0;
}