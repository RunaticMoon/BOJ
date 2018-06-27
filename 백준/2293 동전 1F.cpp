#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];
vector<int> coin;

int func(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;

	int &ret = dp[n];
	if (ret != -1) return ret;
	
	int sum = INT_MAX;
	for (auto i : coin) {
		sum += func(n - i);
	}

	return ret = sum;
}


int main() {
	int n, k, a;
	memset(dp, -1, sizeof(dp));

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> a;
		coin.push_back(a);
	}

	cout << func(k) << endl;

	for (int i = 0; i < 11; ++i) {
		cout << dp[i] << ' ';
	}
	
	system("pause >> null");
	return 0;
}