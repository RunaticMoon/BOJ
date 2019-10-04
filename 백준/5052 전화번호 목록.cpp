#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10;

int T, N;
char str[11];

struct Trie {
	Trie* go[MAX];
	bool output;
	bool goexist;

	Trie() {
		fill(go, go + MAX, nullptr);
		output = goexist = false;
	}
	~Trie() {
		for (int i = 0; i < MAX; i++) {
			if (go[i]) delete go[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') output = true;
		else {
			int next = *key - '0';
			if (!go[next]) go[next] = new Trie;
			goexist = true;
			go[next]->insert(key + 1);
		}
	}

	bool consistent() {
		if (goexist && output) return false;
		for (int i = 0; i < MAX; i++) {
			if (go[i] && !go[i]->consistent()) return false;
		}
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;

		Trie* root = new Trie;

		for (int i = 0; i < N; i++) {
			cin >> str;
			root->insert(str);
		}

		cout << (root->consistent() ? "YES" : "NO") << '\n';
	}

	return 0;
}