#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 1;

int N;
int arr[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}

	cout << *max_element(dp, dp + N);

	return 0;
}