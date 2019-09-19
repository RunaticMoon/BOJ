#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, minNum, tempNum;
string str[51];
string board[2] = { "WBWBWBWB", "BWBWBWBW" };

int compareBoard(int r, int c, char ch) {
	int cnt = 0;

	bool wb;
	if (ch == 'W') wb = false;
	else if (ch == 'B') wb = true;
	else return -1;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (str[r + i][c + j] != board[wb][j]) cnt++;
		}
		wb = !wb;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	minNum = 8 * 8;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			tempNum = compareBoard(i, j, str[i][j]);
			tempNum = min(tempNum, 64 - tempNum);
			minNum = min(minNum, tempNum);
		}
	}

	cout << minNum;

	return 0;
}