#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

enum ops { PLUS, MINUS, MULTI, DIVIDE };

int N;
int arr[101];
int op[4];
int maxNum = INT_MIN, minNum = INT_MAX;

void func(int n, int sum) {
	if (n == N) {
		maxNum = max(maxNum, sum);
		minNum = min(minNum, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;

			switch (i) {
			case PLUS:
				func(n + 1, sum + arr[n]);
				break;
			case MINUS:
				func(n + 1, sum - arr[n]);
				break;
			case MULTI:
				func(n + 1, sum * arr[n]);
				break;
			case DIVIDE:
				func(n + 1, sum / arr[n]);
				break;
			}

			op[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	func(1, arr[0]);

	cout << maxNum << '\n';
	cout << minNum;

	return 0;
}