#include <iostream>
using namespace std;

int main() {
	int N, K, count;
	int coin[10];

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	count = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (K >= coin[i]) {
			K -= coin[i];
			count++;
		}

		if (K == 0) {
			break;
		}
	}

	cout << count << endl;

	return 0;
}