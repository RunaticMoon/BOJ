#include <iostream>
using namespace std;

const int MAX = 1e2 + 1;

int N, M, K;
int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrixA[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> matrixB[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < M; j++) {
				result[i][k] += matrixA[i][j] * matrixB[j][k];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}