#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1;

string T, P;
int fail[MAX];
vector<int> result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, T);
	getline(cin, P);

	// fail 함수 구하기
	for (int i = 1, j = 0; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}

	// KMP
	for (int i = 0, j = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != P[j]) j = fail[j - 1];
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				result.push_back(i - P.size() + 2);
				j = fail[j];
			}
			else j++;
		}
	}

	cout << result.size() << "\n";	
	for (auto& i : result) {
		cout << i << "\n";
	}

	return 0;
}