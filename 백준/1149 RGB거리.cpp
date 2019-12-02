#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1e3 + 1;

enum Color { RED, GREEN, BLUE };

int N;
int house[MAX][3];
int dp[MAX][3];

int func(int n, int c) {
	if (n == 0) {
		return house[0][c];
	}

	int& ret = dp[n][c];
	if (ret != -1) return ret;

	int nc = (c + 1) % 3;
	int mc = (c + 2) % 3;
	return ret = min(func(n - 1, nc), func(n - 1, mc)) + house[n][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		func(N - 1, i);
	}

	cout << min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });

	return 0;
}