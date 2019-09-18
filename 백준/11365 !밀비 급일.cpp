#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (getline(cin, str), str != "END") {
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}

	return 0;
}