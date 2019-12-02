#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e2 + 1;

int T, N;
long long dp[MAX];

long long func(int n) {
	if (n == 1 || n == 2 || n == 3) return 1;
	if (n == 4 || n == 5) return 2;

	long long& ret = dp[n];
	if (ret != -1) return ret;

	return ret = func(n - 1) + func(n - 5);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		cout << func(N) << '\n';
	}

	return 0;
}