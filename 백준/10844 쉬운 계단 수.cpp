#include <iostream>
#include <cstring>
using namespace std;

const int divisor = 1e9;

int N, sum;
int dp[101][10];

int func(int n, int last) {
	int& ret = dp[n][last];
	if (n == 1) return ret = ((last == 0) ? 0 : 1);
	if (ret != -1) return ret;

	int num = 0;
	if (last != 0) num += func(n - 1, last - 1);
	if (last != 9) num += func(n - 1, last + 1);

	return ret = (num % divisor);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 10; i++) {
		sum += func(N, i);
	}

	for (int i = 0; i < 10; i++) {
		cout << dp[2][i] << " ";
	}
	cout << endl;

	cout << sum;

	return 0;
}