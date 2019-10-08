#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, v, maxNum = INT_MIN, minNum = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		maxNum = max(maxNum, v);
		minNum = min(minNum, v);
	}

	cout << minNum << " " << maxNum;

	return 0;
}