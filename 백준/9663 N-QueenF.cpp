#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int N, result;
vector< vector<int> > board;

void print() {
	cout << "---------------------------" << endl;
	for (auto i : board) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
}

void check(int n) {
	if (n == N) {
		result++;
		return;
	}
	bool flag = true;
	for (int i = 0; i < ((n == 0) ? (N + 1)/2 : N); i++) {
		if (board[n][i] == 0) {
			flag = false;
			board[n][i] = n + 1;

			for (int k = 1; k < N - n; k++) {
				if (board[n + k][i] == 0)
					board[n + k][i] = n + 1;
				if (i + k < N) {
					if (board[n + k][i + k] == 0)
						board[n + k][i + k] = n + 1;
				}
				if (i - k >= 0) {
					if (board[n + k][i - k] == 0)
						board[n + k][i - k] = n + 1;
				}
			}

			//print();
			check(n + 1);
			for (int b = 0; b < board.size(); b++) {
				replace(board[b].begin(), board[b].end(), n + 1, 0);
			}
		}
	}

	if (flag) {
		for (int b = 0; b < board.size(); b++) {
			replace(board[b].begin(), board[b].end(), n, 0);
		}
		//cout << "no" << endl;
		//print();
	}
}

int main() {
	cin >> N;

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	for (int i = 0; i < N; i++) {
		vector<int> element;
		element.resize(N);
		board.push_back(element);
	}

	check(0);

	cout << result * 2;
	
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
	cout << "걸린시간 : " << sec.count() << endl;
	system("pause >> null");
	return 0;
}