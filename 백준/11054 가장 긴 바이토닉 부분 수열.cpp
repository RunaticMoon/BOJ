#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e3 + 1;

int N, len;
int arr[MAX];
int dp[MAX], dp2[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dp, dp + MAX, 1);
	fill(dp2, dp2 + MAX, 1);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 1 -> N 방향의 LIS
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// 1 <- N 방향의 LIS
	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	// 두개를 더한값에서 1을 빼는 이유는 중간의 값이 곂치기 때문
	for (int i = 0; i < N; i++) {
		len = max(len, dp[i] + dp2[i] - 1);
	}

	cout << len;

	return 0;
}