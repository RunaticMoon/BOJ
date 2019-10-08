#include <iostream>
using namespace std;

int H, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> M;

	M -= 45;
	if (M < 0) {
		if(--H < 0) H += 24;
		M += 60;
	}

	cout << H << " " << M;

	return 0;
}