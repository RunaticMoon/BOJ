#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, v, maxLen;
stack<int> st;
int a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= N; i++) {
		while (!st.empty() && a[st.top()] > a[i]) {
			int index = st.top();
			st.pop();
			
			int width;
			if (st.empty()) width = i;
			else width = i - st.top() - 1;
			maxLen = max(maxLen, a[index] * width);
		}
		st.push(i);
	}

	cout << maxLen;

	return 0;
}