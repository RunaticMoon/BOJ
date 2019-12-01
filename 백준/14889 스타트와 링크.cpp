#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int N;
int power[21][21];
bool enroll[21];
int minNum = INT_MAX;

int combi(bool ck) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (enroll[i] == ck) {
			for (int j = i + 1; j < N; j++) {
				if (enroll[j] == ck) {
					result += power[i][j];
					result += power[j][i];
				}
			}
		}
	}
	return result;
}

// s는 중복조합 안만들기 위하여
void check(int n, int s) {
	if (n == N / 2) {
		int a = combi(true);
		int b = combi(false);
		minNum = min(minNum, abs(a - b));
		return;
	}

	for (int i = s; i < N; i++) {
		enroll[i] = true;
		check(n + 1, i + 1);
		enroll[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power[i][j];
		}
	}

	check(0, 0);

	cout << minNum;
	
	return 0;
}