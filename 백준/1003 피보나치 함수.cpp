#include <iostream>
#include <utility>
using namespace std;

pair<int, int> memo[41] = { make_pair(1, 0), make_pair(0, 1), };

std::pair<int, int> operator +(const std::pair<int, int>& x, const std::pair<int, int>& y) {
	return std::make_pair(x.first + y.first, x.second + y.second);
}

pair<int, int> fibonacci(int n) {
	if (n == 0)
		return make_pair(1, 0);
	else if (n == 1)
		return make_pair(0, 1);

	pair<int, int>& ret = memo[n];
	if (ret.first == 0 && ret.second == 0)
		ret = fibonacci(n - 1) + fibonacci(n - 2);
	return ret;
}

int main() {
	int T, n;

	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> n;
		cout << fibonacci(n).first << ' ' << fibonacci(n).second << '\n';
	}

	return 0;
}