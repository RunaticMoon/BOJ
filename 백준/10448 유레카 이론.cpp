#include <iostream>
#include <vector>
using namespace std;

vector<int> Tnum;
int T, num, sum;

int find(int num) {
	for (int i = 0; i < Tnum.size(); i++) {
		for (int j = 0; j < Tnum.size(); j++) {
			for (int k = 0; k < Tnum.size(); k++) {
				if (num == Tnum[i] + Tnum[j] + Tnum[k]) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 1; ; i++) {
		if (i*(i + 1) / 2 < 1000) {
			Tnum.push_back(i*(i + 1) / 2);
		}
		else {
			break;
		}
	}

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> num;
		cout << find(num) << endl;
	}

	return 0;
}