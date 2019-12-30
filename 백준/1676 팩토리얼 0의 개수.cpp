#include <iostream>
using namespace std;

int N;
int two, five;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 2; i <= N; i *= 2) {
		two += N / i;
	}

	for (int i = 5; i <= N; i *= 5) {
		five += N / i;
	}

	cout << (two > five ? five : two);

	return 0;
}