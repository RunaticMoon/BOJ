#include <iostream>
#include <cstring>
using namespace std;

long long dp[91][2];

long long func(int n, int stat) {
	long long& ret = dp[n][stat];
	if (n == 1) return ret = 1;
	if (ret != -1) return ret;

	if (stat == 1)
		ret = func(n - 1, 0);
	else if(stat == 0)
		ret = func(n - 1, 1) + func(n - 1, 0);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int N;

	cin >> N;

	cout << func(N, 1) << endl;

	return 0;
}