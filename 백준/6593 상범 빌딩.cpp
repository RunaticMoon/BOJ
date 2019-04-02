#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> tiii;

int L, R, C;
char temp;
int cube[31][31][31];
queue<tiii> q;
int dl[] = { 0, 0, 0, 0, 1, -1 };
int dr[] = { 1, -1, 0, 0, 0, 0 };
int dc[] = { 0, 0, 1, -1, 0, 0 };
tiii goal;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true) {
		cin >> L >> R >> C;
		if (!L && !R && !C) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> temp;

					if (temp == 'S') {
						cube[i][j][k] = 1;
						q.push({ i, j, k });
					}
					else if (temp == 'E') {
						cube[i][j][k] = 0;
						goal = { i, j, k };
					}
					else if (temp == '#') {
						cube[i][j][k] = -1;
					}
					else {
						cube[i][j][k] = 0;
					}
				}
			}
		}

		while (!q.empty()) {
			tiii temp = q.front();
			int& i = get<0>(temp);
			int& j = get<1>(temp);
			int& k = get<2>(temp);
			q.pop();

			for (int c = 0; c < 6; c++) {
				int pi = i + dl[c];
				int pj = j + dr[c];
				int pk = k + dc[c];

				if (0 <= pi && pi < L && 0 <= pj && pj < R && 0 <= pk && pk < C && cube[pi][pj][pk] == 0) {
					cube[pi][pj][pk] = cube[i][j][k] + 1;
					q.push({ pi, pj, pk });
				}
			}
		}

		int& ei = get<0>(goal);
		int& ej = get<1>(goal);
		int& ek = get<2>(goal);

		if (cube[ei][ej][ek] == 0) cout << "Trapped!" << "\n";
		else {
			cout << "Escaped in " << cube[ei][ej][ek] - 1 << " minute(s)." << "\n";
		}
	}


	return 0;
}