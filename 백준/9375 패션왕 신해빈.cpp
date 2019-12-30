#include <iostream>
#include <map>
#include <string>
using namespace std;

int T, N;
map<string, int> m;
string name, wear;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> name >> wear;
			m[wear]++;
		}

		// (x + 1) * (y + 1) * ... (z + 1) - 1
		// �� �ǻ��� ���� +1 (���� ���)
		// ������ -1�� ���� ���� ����� ��
		int ans = 1;
		for (auto& w : m) {
			ans *= w.second + 1;
		}

		cout << ans - 1 << '\n';
		m.clear();
	}

	return 0;
}