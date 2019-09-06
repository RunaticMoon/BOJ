#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int Row = 12;
const int Col = 6;

char field[Row][Col];
int chain = -1;
bool isUsed[Row][Col];
queue<int> q;
int arrow[5] = { -1, 0, 1, 0, -1 };

void dfs(int r, int c) {
	const char& ret = field[r][c];
	isUsed[r][c] = true;
	q.push(r * Col + c);

	for (int i = 0; i < 4; i++) {
		const int& dr = r + arrow[i];
		const int& dc = c + arrow[i + 1];
		const char& next = field[dr][dc];
		
		if (dr >= 0 && dr < Row && dc >= 0 && dc < Col &&
			!isUsed[dr][dc] && next == ret) {
			dfs(dr, dc);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력받기
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			field[i][j] = cin.get();
		}

		// 개행문자 버리기
		cin.get();
	}

	// 연쇄가 끝날때 까지
	bool flag = true;
	while (flag) {
		// 연쇄가 없다면 종료
		flag = false;
		chain++;
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				const char& pos = field[i][j];

				if (!isUsed[i][j] && pos != '.') {
					dfs(i, j);
				}

				if (q.size() >= 4) {
					flag = true;

					while (!q.empty()) {
						int idx = q.front();
						q.pop();

						int pr = idx / Col;
						int pc = idx % Col;

						field[pr][pc] = '.';
					}
				}
				else {
					while (!q.empty()) q.pop();
				}
			}
		}
		memset(isUsed, false, sizeof(isUsed));

		// 내리기
		for (int i = 0; i < Col; i++) {
			int bottom = Row - 1;
			int top = Row - 2;

			while (top >= 0) {
				if (field[bottom][i] == '.' && field[top][i] != '.')
					swap(field[bottom][i], field[top][i]);

				if (field[bottom][i] != '.') bottom--;

				if (field[top][i] == '.') top--;

				if (bottom <= top) top = bottom - 1;
			}
		}

		// 디버그
		/*for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				cout << field[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
	}
	
	cout << chain;

	return 0;
}