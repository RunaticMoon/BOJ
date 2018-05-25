#include <iostream>
using namespace std;

int arr[10000];

int main() {
	int arrayNumber, targetNumber;
	int p = 0, q = 0, sum = 0, result = 0;

	cin >> arrayNumber >> targetNumber;

	for (int i = 0; i < arrayNumber; ++i) {
		cin >> arr[i];
	}

	while (q <= arrayNumber) {
		if (sum > targetNumber) {
			sum -= arr[p++];
		}
		else if (sum < targetNumber) {
			sum += arr[q++];
		}
		else {
			++result;
			sum += arr[q++];
		}
	}

	cout << result;

	return 0;
}