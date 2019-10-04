#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAX = 'z' - 'a' + 1;

char str[81];
int N;

struct Trie {
	Trie* go[MAX];
	bool output;
	int branch;
	int words;

	Trie() {
		fill(go, go + MAX, nullptr);
		output = false;
		branch = words = 0;
	}

	~Trie() {
		for (int i = 0; i < MAX; i++) {
			if (go[i]) delete go[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			branch++;
			output = true;
		}
		else {
			int next = *key - 'a';
			if (!go[next]) {
				go[next] = new Trie;
				branch++;
			}

			words++;
			go[next]->insert(key + 1);
		}
	}

	long long check(bool isRoot = false) {
		long long result = 0;

		if (isRoot || branch > 1) result = words;
		
		for (int i = 0; i < MAX; i++) {
			if (go[i]) result += go[i]->check();
		}
		return result;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N;
		if (cin.eof()) break;

		Trie* root = new Trie;
		for (int i = 0; i < N; i++) {
			cin >> str;
			root->insert(str);
		}

		cout << fixed << setprecision(2) << (double)root->check(true) / N << endl;

		delete root;
	}

	return 0;
}