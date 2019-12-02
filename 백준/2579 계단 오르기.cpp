#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 3e2 + 1;
const int INF = -1e6;

int N;
int stair[MAX];
int dp[MAX][2];
/*
	1¹ø ¶Ú È½¼ö
*/

int func(int n, int c) {
	if (n == 0) return 0;
	if (n == 1) return stair[1];

	int& ret = dp[n][c];
	if (ret != -1) return ret;

	switch (c) {
	case 0:
		return ret = max(func(n - 2, 0), func(n - 2, 1)) + stair[n];
	case 1:
		return ret = func(n - 1, 0) + stair[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}

	for (int i = 0; i < 2; i++) {
		func(N, i);
	}

	cout << max(dp[N][0], dp[N][1]);

	return 0;
}