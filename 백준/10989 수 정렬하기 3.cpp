#include <iostream>
using namespace std;

const int MAX = 1e7 + 1;
const int MAX_NUM = 1e4 + 1;

int N, v;
//int arr[MAX];
int acc[MAX_NUM]; // Accumulate 누적되다.
//int result[MAX];

// Counting Sort
// 메모리 초과로 인하여 배열 저장, 누적합, 배열변환하는 과정 생략

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		acc[v]++;
	}

	/*for (int i = 1; i < MAX_NUM; i++) {
		acc[i] += acc[i - 1];
	}*/

	for (int i = 0; i < MAX_NUM; i++) {
		if (acc[i] > 0) {
			for (int j = 0; j < acc[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	/*for (int i = N - 1; i >= 0; i--) {
		result[--acc[arr[i]]] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << '\n';
	}*/

	return 0;
}