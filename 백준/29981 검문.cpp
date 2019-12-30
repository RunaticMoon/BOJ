#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e2 + 1;

int N;
int arr[MAX];
vector<int> v;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

/*
	a1 = a * n + r
	a2 = a * m + r

	a1 - a2 = a(n - m)
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int ans = arr[1] - arr[0];
	for (int i = 2; i < N; i++) {
		ans = gcd(ans, arr[i] - arr[i - 1]);
	}

	for (int i = 2; i*i <= ans; i++) {
		if (ans % i == 0) {
			if (i == ans / i) v.push_back(i);
			else {
				v.push_back(i);
				v.push_back(ans / i);
			}
		}
	}
	v.push_back(ans);

	sort(v.begin(), v.end());

	for (auto& m : v) {
		cout << m << ' ';
	}

	return 0;
}