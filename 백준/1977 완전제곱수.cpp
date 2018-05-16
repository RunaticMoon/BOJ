#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N;
	int min, max, sum = 0;

	cin >> M >> N;

	min = (int)ceil(sqrt(M));
	max = (int)sqrt(N);

	for (int i = min; i <= max; ++i) {
		sum += i * i;
	}

	if (sum == 0)
		cout << -1;
	else {
		cout << sum << endl;
		cout << min * min << endl;
	}

	return 0;
}