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

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int N, L, temp, count;
	vector<int> arr;

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	arr.push_back(INT_MAX);

	count = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] - arr[i] >= L) {
				count++;
				i = j - 1;
				break;
			}
		}
	}

	cout << count << endl;

	return 0;
}
*/