#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int mul = 0;
	for (int i = 0;; i++) {
		mul += i;
		if (N == 1) {
			cout << 1;
			break;
		}
		if (2 + 6 * (mul - i) <= N && N <= 1 + 6 * mul) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}