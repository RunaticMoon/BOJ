#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1e2 + 1;
const int KMAX = 1e5 + 1;

int N, K;
int w, v;
pii arr[MAX];
int dp[MAX][KMAX];

int func(int n, int c) {
	if (n == 0) return 0;

	int& ret = dp[n][c];
	if (ret != -1) return ret;

	if (arr[n].first > c)
		return ret = func(n - 1, c);
	else
		return ret = max(func(n - 1, c - arr[n].first) + arr[n].second, func(n - 1, c));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	cout << func(N, K);

	return 0;
}