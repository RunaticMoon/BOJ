#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> blank;

void func(int n) {
	if (n == blank.size()) {
		return;
	}
	int r = blank[n].first;
	int c = blank[n].second;
	int &ret = board[r][c];
}

int main() {
	ifstream fin("input.txt");

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			fin >> board[i][j];
			if (board[i][j] == 0) {
				blank.push_back({ i, j });
			}
		}
	}

	for (auto p : blank) {
		int r = p.first;
		int c = p.second;

		bool num[10] = { false, };
		
		for (int i = 0; i < 9; i++) {
			num[board[r][i]] = true;
			num[board[i][c]] = true;
		}
		
		int r1 = r / 3;
		int c1 = c / 3;
		for (int i = r1; i < r1 + 3; i++) {
			for (int j = c1; j < c1 + 3; j++) {
				num[board[i][j]] = true;
			}
		}
		

	}
	
	func(0);

	for (auto i : blank) {
		cout << i.first << ' ' << i.second << endl;
	}

	system("pause >> null");

	return 0;
}