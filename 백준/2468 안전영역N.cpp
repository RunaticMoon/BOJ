#include <iostream>
using namespace std;

int area[100][100];
bool safe[100][100];

int main() {
	int rowNumber, max = 0;

	cin >> rowNumber;

	for (int i = 0; i < rowNumber; ++i) {
		for (int j = 0; j < rowNumber; ++j) {
			cin >> area[i][j];
			if (area[i][j] > max)
				max = area[i][j];
		}
	}

	for (int i = 1; i <= max; ++i) {

	}

	return 0;
}

/*
DFS : 깊이우선탐색
방향우선순위 : → ↓ ← ↑

1. 잠겼는지 확인
2. 범위를 벗어났는지 확인
*/