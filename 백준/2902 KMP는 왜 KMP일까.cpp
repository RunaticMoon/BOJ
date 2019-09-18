#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char ch;
	bool flag = true;

	while ((ch = cin.get()) != EOF) {
		if (flag) {
			cout << ch;
			flag = false;
		}
		if (ch == '-') flag = true;
	}

	return 0;
}