#include <iostream>
#include <string>
#include <set>
using namespace std;

const int MAX = 2e4 + 1;

struct comp {
	bool operator() (const string& a, const string& b) {
		if (a.length() == b.length())
			return a < b;
		else return a.length() < b.length();
	}
};

int N;
set<string, comp> word;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		word.insert(str);
	}

	for (auto& w : word) {
		cout << w << '\n';
	}

	return 0;
}