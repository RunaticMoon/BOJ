#include <iostream>
using namespace std;

int main() {
	// cin�� cout�� ������ �����Ѵ�.
	cin.tie(NULL);
	// cin/cout�� stdin/stdout�� ���۰����� �����Ѵ�.
	ios_base::sync_with_stdio(false);

	int T, num1, num2;

	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> num1 >> num2;

		cout << num1 + num2 << '\n';
	}
}