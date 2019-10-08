#include <iostream>
using namespace std;

int N, num, chk;

bool check(int n) {
	int six = 0;

	while (n != 0 && six < 3) {
		if (n % 10 == 6) six++;
		else six = 0;
		n /= 10;
	}

	return ((six >= 3) ? true : false);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (chk != N) {
		if (check(++num)) {
			chk++;
		}
	}

	cout << num;

	return 0;
}