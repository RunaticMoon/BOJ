#include <iostream>
#include <cstring>
using namespace std;

int dp[12];

int func(int n) {
	int &ret = dp[n];
	
	if (ret != -1) return ret;
	if (n == 0) return 1;

	return ret = func(n - 1) + func(n - 2) + func(n - 3);
}

int main() {
	int n, T;
	memset(dp, -1, sizeof(dp));

	dp[1] = 1;
	dp[2] = 2;

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;

		cout << func(n) << endl;
	}

	return 0;
}