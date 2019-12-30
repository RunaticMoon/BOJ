#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		getline(cin, str);
		if (str[0] == '.') break;

		int len = str.length();
		for(auto& ch : str) {
			if (ch == '(' || ch == '[') s.push(ch);
			if (ch == ')') {
				if (!s.empty() && s.top() == '(') s.pop();
				else {
					s.push('-');
					break;
				}
			}
			if (ch == ']') {
				if (!s.empty() && s.top() == '[') s.pop();
				else {
					s.push('-');
					break;
				}
			}
		}

		if (s.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';

		while (!s.empty()) s.pop();
	}

	return 0;
}