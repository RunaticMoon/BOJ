#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5e1 + 1;

int N;
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cout << arr[0] * arr[N - 1];

	return 0;
}