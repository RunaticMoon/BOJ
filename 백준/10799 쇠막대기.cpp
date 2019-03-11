#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> arr;
string str;
int counter;
char bc = '#';

int main() {
	cin >> str;

	for (auto c : str) {
		if (c == ')') {
			arr.pop();
			if (bc == '(') {
				counter += arr.size();
			}
			else {
				counter++;
			}
		}
		else arr.push(c);
		bc = c;
	}

	cout << counter;

	return 0;
}