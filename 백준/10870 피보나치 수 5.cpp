#include <iostream>
using namespace std;

int n;

int fibonachi(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;

	return fibonachi(n - 1) + fibonachi(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << fibonachi(n);

	return 0;
}