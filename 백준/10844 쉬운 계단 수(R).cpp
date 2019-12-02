#include <iostream>
#include <cstring>
using namespace std;

const int divNum = 1e9;
const int MAX = 1e2 + 1;

int N, sum;
int dp[MAX][10];

int func(int n, int c) {
	if (c < 0 || c > 9) return 0;
	if (n == 1) return (c == 0) ? 0 : 1;

	int& ret = dp[n][c];
	if (ret != -1) return ret;

	return ret = (func(n - 1, c - 1) + func(n - 1, c + 1)) % divNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < 10; i++) {
		sum = (sum + func(N, i)) % divNum;
	}

	cout << sum;

	return 0;
}