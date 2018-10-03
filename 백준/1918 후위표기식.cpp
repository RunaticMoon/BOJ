#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> opStack;
string str, result;

int main() {
	cin >> str;

	for (auto s : str) {
		if (s >= 'A' && s <= 'Z') {
			result.push_back(s);
		}
		else {
			switch (s) {
			case '(':
				opStack.push(s);
				break;
			case ')':
				while (opStack.top() != '(') {
					result.push_back(opStack.top());
					opStack.pop();
				}
				opStack.pop();
				break;
			case '+':
			case '-':
				while (!opStack.empty() && opStack.top() != '(') {
					result.push_back(opStack.top());
					opStack.pop();
				}
				opStack.push(s);
				break;
			case '*':
			case '/':
				if (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/')) {
					result.push_back(opStack.top());
					opStack.pop();
				}
				opStack.push(s);
				break;
			}
		}
	}

	while (!opStack.empty()) {
		result.push_back(opStack.top());
		opStack.pop();
	}

	cout << result;

	return 0;
}