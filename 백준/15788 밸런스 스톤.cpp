/*
	ºÐ·ù: 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int maxN = 501;

int N, k;
int map[maxN][maxN];
int row, col;
long long ld;
bool flag;

long long leftDiagSum() {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += map[i][i];
	}
	return ans;
}

long long rightDiagSum() {
	long long ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		ans += map[N - i - 1][i];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			map[i][N] += map[i][j];
			map[N][j] += map[i][j];
			if (map[i][j] == 0) {
				row = i;
				col = j;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i != row && map[0][N] != map[i][N])
			flag = true;
	}
	for (int i = 0; i < N; i++) {
		if (i != col && map[N][0] != map[N][i])
			flag = true;
	}

	map[row][col] = map[N][0] - map[row][N];
	ld = leftDiagSum();
	if (ld != rightDiagSum())
		flag = true;

	if (ld != map[row][N] || map[N][col] || ld != map[N][col])
		flag = true;

	if (flag) cout << -1;
	else cout << map[row][col];

	return 0;
}