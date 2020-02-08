#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, v;
string cmd;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		
		if (cmd == "push") {
			cin >> v;
			q.push(v);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << -1;
			else {
				cout << q.front();
				q.pop();
			}
			cout << '\n';
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << q.empty() << '\n';
		}
		else if (cmd == "front") {
			if (q.empty()) cout << -1;
			else {
				cout << q.front();
			}
			cout << '\n';
		}
		else if (cmd == "back") {
			if (q.empty()) cout << -1;
			else {
				cout << q.back();
			}
			cout << '\n';
		}
	}

	return 0;
}