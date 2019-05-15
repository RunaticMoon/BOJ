#include <iostream>
#include <cstring>
using namespace std;

int dp[101][10001];
int coin[101];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
	}

	for (int i = 0; i <= k; ++i) {
		int& ret = dp[0][i];
		if (i % coin[0] == 0) {
			ret = 1;
		}
		else {
			ret = 0;
		}
	}

	for (int i = 1; i < n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= k; ++j) {
			int& ret = dp[i][j];

			ret = 0;

			for (int l = 0; l <= i; ++l) {
				if (j - coin[l] >= 0) {
					ret += dp[l][j - coin[l]];
				}
			}
		}
	}

	cout << dp[n - 1][k];

	return 0;
}