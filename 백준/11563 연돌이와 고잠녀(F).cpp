#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double s[2001][4], a[2001][4];

double distance(double x1, double y1, double x2, double y2) {
	double dx = abs(x1 - x2);
	double dy = abs(y1 - y2);

	return sqrt(dx*dx + dy * dy);
}

int main() {
	int n, m;
	double min = INT_MAX;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// A-B �� C-D�����̶� ����
			// 1. A�� C, D��
			double len = distance(s[i][0], s[i][1], a[j][0], a[j][1]);
			len = std::min(len, distance(s[i][0], s[i][1], a[j][2], a[j][3]));

			// 2. B�� C, D��
			len = std::min(len, distance(s[i][2], s[i][3], a[j][0], a[j][1]));
			len = std::min(len, distance(s[i][2], s[i][3], a[j][2], a[j][3]));

			// 3. C�� D���� ������ ����
			
		}
	}


	return 0;
}