#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 1;

int N;
int grape[MAX];
int dp[MAX][3];

// 몇칸을 뛰든 상관x
// n부터 c개 연속으로 마심

int func(int n, int c) {
	if (n == 0) return 0;
	if (n == 1 && c == 1) return grape[1];

	int& ret = dp[n][c];
	if (ret != -1) return ret;

	switch (c) {
	case 0:
		return ret = max({ func(n - 1, 0), func(n - 1, 1), func(n - 1, 2) });
	case 1:
		return ret = func(n - 1, 0) + grape[n];
	case 2:
		return ret = func(n - 1, 1) + grape[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> grape[i];
	}

	for (int i = 0; i < 3; i++) {
		func(N, i);
	}

	cout << max({ dp[N][0], dp[N][1], dp[N][2] });

	return 0;
}