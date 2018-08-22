#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N;
int dp[3][100001];
int sticker[2][100001];

/*
	[0]
	00
	00

	[1]
	=*
	*0

	[2]
	*0
	=*
*/

int func(int n, int stat) {
	int &ret = dp[stat][n];
	if (n == N) return 0;
	if (ret != -1) return ret;

	int result = func(n + 1, 0);
	if (stat != 1) result = max(result, func(n + 1, 1) + sticker[0][n]);
	if (stat != 2) result = max(result, func(n + 1, 2) + sticker[1][n]);

	return ret = result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < N; i++) {
			cin >> sticker[0][i];
		}
		for (int i = 0; i < N; i++) {
			cin >> sticker[1][i];
		}

		cout << func(0, 0) << endl;
	}

	return 0;
}