#include <iostream>
using namespace std;

const int MAX = 1e3 + 1;

int N;
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		// Insertion Sort
		for (int j = i; j > 0; j--) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}