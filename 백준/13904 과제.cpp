#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int result[1001];
pii arr[1001];

bool great(pii& a, pii& b) {
	return a.second > b.second;
}

int main() {
	int N, n;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + N, great);

	for (int i = 0; i < N; i++) {
		n = arr[i].first;

		while (n > 0) {
			if (result[n] == 0) {
				result[n] = arr[i].second;
				break;
			}
			n--;
		}
	}

	for (int i = 1; i < 1001; i++) {
		result[0] += result[i];
	}

	cout << result[0];

	return 0;
}