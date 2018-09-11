#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 지도의 크기 5 ~ 25
int N;
int map[25][25];
bool visited[25][25];
vector<int> result;

int func(int i, int j) {
	visited[i][j] = true;
	int result = 1;

	if (j - 1 >= 0) {
		if (map[i][j - 1] == 1 && !visited[i][j - 1]) {
			result += func(i, j - 1);
		}
	}
	if (i - 1 >= 0) {
		if (map[i - 1][j] == 1 && !visited[i - 1][j]) {
			result += func(i - 1, j);
		}
	}
	if (j + 1 < N) {
		if (map[i][j + 1] == 1 && !visited[i][j + 1]) {
			result += func(i, j + 1);
		}
	}
	if (i + 1 < N) {
		if (map[i + 1][j] == 1 && !visited[i + 1][j]) {
			result += func(i + 1, j);
		}
	}
	return result;
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = cin.get() - '0';
			if (map[i][j] == '\n' - '0') {
				map[i][j] = cin.get() - '0';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				result.push_back(func(i, j));
			}
		}
	}

	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (auto i : result) {
		cout << i << endl;
	}

	return 0;
}