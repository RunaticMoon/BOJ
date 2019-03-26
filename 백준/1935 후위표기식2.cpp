#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

int N, arr[26];
string str;
stack<double> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (char c : str) {
		if ('A' <= c && c <= 'Z') {
			st.push(arr[c - 'A']);
		}
		else {
			double v1, v2;
			v2 = st.top(); st.pop();
			v1 = st.top(); st.pop();

			switch (c) {
			case '+':
				st.push(v1 + v2);
				break;
			case '-':
				st.push(v1 - v2);
				break;
			case '*':
				st.push(v1 * v2);
				break;
			case '/':
				st.push(v1 / v2);
				break;
			}
		}
	}

	cout << fixed << setprecision(2) << st.top();

	return 0;
}