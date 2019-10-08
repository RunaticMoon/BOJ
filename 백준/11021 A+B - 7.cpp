#include <iostream>
using namespace std;

int T;
int A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> A >> B;
		cout << "Case #" << test_case << ": " << A + B << "\n";
	}

	return 0;
}