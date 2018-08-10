#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

int arr[10001], val[10001];

int main() {
	int n, p, c, w;
	
	memset(arr, -1, sizeof(arr));
	memset(val, -1, sizeof(val));

	freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> p >> c >> w;

		arr[c] = p;
		val[c] = w;
	}




	for (int i = 1; i <= n; ++i) {
		cout << "[" << i << "] " << arr[i] << " / " << val[i] << endl;
	}

	while (true) {
		system("pause >> null");
	}

	return 0;
}