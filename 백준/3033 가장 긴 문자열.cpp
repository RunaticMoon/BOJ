#include <iostream>
#include <vector>
using namespace std;

int **road;

int getRoad(int r, int c) {
	if (r < 1 || c < 1)
		return 1;

	int& ret = road[r][c];
	if (ret == 0)
		ret = getRoad(r - 1, c) + getRoad(r, c - 1);

	return ret;
}

int main() {
	int road_length, case_number, num1, num2, len;
	vector<pair<int, int>> pos;
	vector<int> result;

	cin >> road_length;

	road = new int*[road_length + 1];
	for (int i = 0; i < road_length + 1; ++i) {
		road[i] = new int[road_length + 1];
		fill(road[i], road[i] + road_length + 1, 0);
	}

	cin >> case_number;

	for (int i = 0; i < case_number; ++i) {
		cin >> num1 >> num2;
		pos.push_back(make_pair(num1, num2));
	}

	pair<int, int> car1 = make_pair(1, 1);
	pair<int, int> car2 = make_pair(road_length, road_length);

	len = 0;
	for (int i = 0; i < case_number; ++i) {
		num1 = getRoad(abs(pos[i].first - car1.first), abs(pos[i].second - car1.second));
		num2 = getRoad(abs(pos[i].first - car2.first), abs(pos[i].second - car2.second));

		cout << endl;
		cout << pos[i].first << ' ' << pos[i].second << endl;
		cout << "nm1 => " << abs(pos[i].first - car1.first) << ' ' << abs(pos[i].second - car1.second) << endl;
		cout << "nm2 => " << abs(pos[i].first - car2.first) << ' ' << abs(pos[i].second - car2.second) << endl;
		cout << "num1 : " << num1 << ", num2 : " << num2 << endl;

		if (num1 > num2) {
			len += num2;

			car2 = make_pair(pos[i].first, pos[i].second);
			result.push_back(2);
		}
		else {
			len += num1;

			car1 = make_pair(pos[i].first, pos[i].second);
			result.push_back(1);
		}
	}

	cout << len << '\n';
	for (auto& i : result) {
		cout << i << '\n';
	}

	system("pause >> null");
	return 0;
}