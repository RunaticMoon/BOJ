#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 1;

int N;
int arr[MAX];

// quick sort
void qsort(int i, int j) {
	if (i >= j) return;
	int pivot = arr[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right) {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++; right--;
		}
	}

	qsort(i, right);
	qsort(left, j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	qsort(0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}