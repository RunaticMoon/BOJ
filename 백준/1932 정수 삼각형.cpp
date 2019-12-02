#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 5e2 + 1;
const int MAX_SQUARE = (MAX * (MAX + 1)) / 2;

int N;
int tri[MAX_SQUARE];
int dp[MAX_SQUARE];

int func(int depth, int n) {
	if (depth == N) {
		return tri[n];
	}

	int& ret = dp[n];
	if (ret != -1) return ret;

	return ret = max(func(depth + 1, n + depth), func(depth + 1, n + depth + 1)) + tri[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N*(N + 1) / 2; i++) {
		cin >> tri[i];
	}

	cout << func(1, 0);

	return 0;
}