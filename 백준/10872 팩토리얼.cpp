#include <iostream>
using namespace std;

int N;

long long fact(int n) {
	if (n == 0) return 1;
	else return n * fact(n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cout << fact(N);

	return 0;
}