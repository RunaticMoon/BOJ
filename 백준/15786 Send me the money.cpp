/*
	분류: 문자열
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, idx;
string plane;
vector<string> postit;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	cin >> plane;
	postit.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> postit[i];
	}

	for (int i = 0; i < M; i++) {
		const string& str = postit[i];
		idx = 0;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == plane[idx]) {
				idx++;
			}

			if (idx == N) break;
		}

		cout << ((idx == N) ? "true" : "false") << "\n";
	}

	return 0;
}