#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int N, n, ans = 0;
	string str[100];
	int alphabet[26];
	bool check = false;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> str[i];
	}

	for (int i = 0; i < N; ++i) {
		memset(alphabet, -1, sizeof(alphabet));
		check = true;
		for (int j = 0; j < str[i].length(); ++j) {
			n = str[i][j] - 'a';
			if (alphabet[n] == -1)
				alphabet[n] = j;
			else if (alphabet[n] == j - 1)
				alphabet[n] = j;
			else
				check = false;
		}
		if (check)
			ans++;
	}

	cout << ans << endl;

	return 0;
}