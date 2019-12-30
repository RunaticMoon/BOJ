#include <iostream>
using namespace std;

const int MAX = 1e2 + 1;

int N;
int arr[MAX];

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int& ring = arr[0];
	for (int i = 1; i < N; i++) {
		int ans = gcd(ring, arr[i]);
		cout << ring / ans << '/' << arr[i] / ans << '\n';
	}

	return 0;
}