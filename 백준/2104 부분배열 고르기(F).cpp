#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001], N;
long long result;

// [a, b)
long long func(int a, int b) {
	cout << "IN : func(" << a << ", " << b << ")" << endl;
	if (a == b) return 0;
	if (a + 1 == b) return arr[a];

	int mid = (a + b) / 2;
	long long result = max(func(a, mid), func(mid + 1, b));
	long long high = 0, sum = arr[mid];

	cout << "-----------------------------" << endl;
	cout << "func(" << a << ", " << b << ")" << endl;

	int l = mid, r = mid;
	int min = 0;
	while (l != a || r + 1 != b) {
		int left = (l - 1 >= a) ? arr[l - 1] : -1;
		int right = (r + 1 < b) ? arr[r + 1] : -1;

		cout << "l : " << l << ", r : " << r << ", left : " <<  left << ", right : " << right;
		
		if (left > right) {
			sum += left;
			l--;

			if (left < min && left > 0) min = left;
		}
		else {
			sum += right;
			r++;

			if (right < min && right > 0) min = left;
		}
		cout << ", sum : " << sum << endl;
		if (sum > high) {
			high = sum;
		}
	}

	cout << "result : " << result << ", high : " << high << ", min : " << min << ", return : " << max(result, high) * min << endl;

	return max(result, high) * min;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << func(0, N);

	return 0;
}