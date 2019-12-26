#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1e3 + 1;

string str, comp;
int lcs[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> comp;

	int clen = comp.length();
	int slen = str.length();

	for (int i = 0; i < clen; i++) {
		for (int j = 0; j < slen; j++) {
			if (comp[i] == str[j])
				lcs[i + 1][j + 1] = lcs[i][j] + 1;
			else 
				lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
		}
	}

	cout << lcs[clen][slen];

	return 0;
}