#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e6 + 1;
const int divNum = 15746;

int N;
int dp[MAX];

int func(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int& ret = dp[n];
	if (ret != -1) return ret;

	return ret = (func(n - 1) + func(n - 2)) % divNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	cout << func(N);

	return 0;
}