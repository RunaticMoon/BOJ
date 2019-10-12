#include <iostream>
using namespace std;

int T;
int k, n;
int arr[15][15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 14; i++) {
		arr[0][i] = i;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> k;
		cin >> n;

		cout << arr[k][n] << '\n';
	}

	return 0;
}