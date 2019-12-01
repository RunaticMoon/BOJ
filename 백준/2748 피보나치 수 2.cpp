#include <iostream>
#include <cstring>
using namespace std;

int N;
long long dp[91];

long long fibonachi(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	long long& ret = dp[n];
	if (ret != -1) {
		return ret;
	}

	return ret = fibonachi(n - 1) + fibonachi(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	cout << fibonachi(N);

	return 0;
}