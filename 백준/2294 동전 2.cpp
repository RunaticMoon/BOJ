#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	보고 풀었는데도 이해가 안됨...
*/

int N, K;
int dp[101][10001];
int coin[101];

int func(int n, int k) {
	int& ret = dp[n][k];
	if (n == N) {
		if (k == 0) return 0;
		else return 1000000000;
	}
	if (ret != -1) return ret;

	int result = func(n+1, k);
	int& c = coin[n];

	if (k >= c) result = min(result, func(n, k - c) + 1);
	return ret = result;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int result = func(0, K);
	if (result == 1000000000) cout << "-1";
	else cout << result;

	return 0;
}