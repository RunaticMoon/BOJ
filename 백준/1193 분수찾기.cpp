#include <iostream>
using namespace std;

int N, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1;; sum += i++) {
		if (sum < N && N <= sum + i) {
			if (i % 2 == 0) {
				cout << N - sum << '/' << (i + 1) - (N - sum);
			}
			else {
				cout << (i + 1) - (N - sum) << '/' << N - sum;
			}
			break;
		}
	}

	return 0;
}