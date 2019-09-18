#include <iostream>
using namespace std;

int T;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> a >> b;
		cout << a + b << "\n";;
	}

	return 0;
}