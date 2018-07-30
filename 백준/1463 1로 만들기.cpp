#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int dp[1000001];

int func(int n) {
	int &ret = dp[n];
	
	if (ret != -1) return ret;
	if (n == 1) return ret = 0;

	int num = INT_MAX;
	if (n % 3 == 0) num = min(num, func(n / 3) + 1);
	if (n % 2 == 0) num = min(num, func(n / 2) + 1);
	num = min(num, func(n - 1) + 1);

	return ret = num;
}

int main() {
	int N;
	memset(dp, -1, sizeof(dp));

	cin >> N;

	cout << func(N);

	return 0;
}