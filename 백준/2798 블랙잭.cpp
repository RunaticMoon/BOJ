#include <iostream>
using namespace std;

const int MAX = 1e2 + 1;

int N, M;
int card[MAX];
int result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum <= M && sum > result) {
					result = sum;
				}
			}
		}
	}

	cout << result;

	return 0;
}