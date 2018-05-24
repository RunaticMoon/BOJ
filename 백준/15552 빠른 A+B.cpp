#include <iostream>
using namespace std;

int main() {
	// cin과 cout의 연결을 해제한다.
	cin.tie(NULL);
	// cin/cout과 stdin/stdout의 버퍼공유를 해제한다.
	ios_base::sync_with_stdio(false);

	int T, num1, num2;

	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		cin >> num1 >> num2;

		cout << num1 + num2 << '\n';
	}
}