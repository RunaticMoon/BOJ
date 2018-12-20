#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, L, start, end, count;
	int arr[1001];

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	count = 0;
	for (int i = 0; i < N; i++) {
		start = arr[i];
		count++;

		for (int j = i + 1; j < N; j++) {
			end = arr[j];

			if (end - start <= L - 1) {
				i++;
			}
			else {
				break;
			}
		}
	}

	cout << count << endl;

	return 0;
}