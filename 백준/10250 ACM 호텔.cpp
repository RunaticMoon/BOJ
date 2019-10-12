#include <iostream>
#include <cmath>
using namespace std;

int T;
int H, W, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> H >> W >> N;

		cout << (N%H == 0 ? H : N % H)
			<< ((int)ceil((double)N / H) < 10 ? "0" : "")
			<< (int)ceil((double)N / H) << '\n';
	}

	return 0;
}