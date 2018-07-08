#include <iostream>
using namespace std;

int arr[51][51];

int main() {
	int N, M, max = 1;

	cin >> N >> M;

	cin.ignore();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			arr[i][j] = cin.get() - '0';
		}
		cin.get();
	}

	// 왼쪽위 (i, j) 오른쪽 아래 (i + k, j + k)
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			for (int k = 1; (i + k < N && j + k < M); ++k) {
				if (arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i + k][j + k]) {
					if (max < (k + 1)*(k + 1)) {
						max = (k + 1) * (k + 1);
					}
				}
			}
		}
	}

	cout << max;

	return 0;
}