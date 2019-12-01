#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int board[9][9];
vector<pii> v;
bool flag;

void check(bool A[], int r, int c) {
	memset(A, false, 10);
	for (int i = 0; i < 9; i++) {
		A[board[r][i]] = true;
		A[board[i][c]] = true;
	}

	int dr = (r / 3) * 3;
	int dc = (c / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[board[dr + i][dc + j]] = true;
		}
	}
}

void func(int n) {
	if (n == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		flag = true;
		return;
	}
	if (flag) return;

	pii& point = v[n];

	bool isOk[10];
	check(isOk, point.first, point.second);

	for (int j = 1; j < 10; j++) {
		if (!isOk[j]) {
			board[point.first][point.second] = j;
			func(n + 1);
			board[point.first][point.second] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				v.push_back({ i, j });
			}
		}
	}

	func(0);

	return 0;
}