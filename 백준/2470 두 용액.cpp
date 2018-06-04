#include <iostream>
#include <set>
#include <cmath>
#include <functional>
using namespace std;

int main() {
	int N, num, sum, min = 1000000000, tempN = 1000000000;
	set<int> plus;
	set<int, greater<int>> minus;
	set<int>::iterator pit, mit;
	pair<int, int> index = make_pair(1000000000, 1000000000), temp = make_pair(1000000000, 1000000000);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		if (num > 0) {
			plus.insert(num);
		}
		else {
			minus.insert(num);
		}
	}

	pit = plus.begin();
	mit = minus.begin();

	if (minus.size() >= 2) {
		tempN = *mit + *(++mit);
		temp.first = *mit;
		temp.second = *(--mit);
	}
	if (plus.size() >= 2) {
		min = *pit + *(++pit);
		index.first = *pit;
		index.second = *(--pit);
	}

	if (abs(tempN) < abs(min)) {
		min = tempN;
		index = temp;
	}

	while (true) {
		if (minus.size() == 0 || plus.size() == 0) {
			break;
		}

		sum = *pit + *mit;
		if (abs(sum) < abs(min)) {
			min = sum;
			index = make_pair(*pit, *mit);
		}

		if ((sum >= 0 || pit == plus.end()) && mit != minus.end()) {
			mit++;
		}
		else if ((sum < 0 || mit == minus.end()) && pit != plus.end()) {
			pit++;
		}

		if (mit == minus.end() || pit == plus.end()) {
			break;
		}
	}

	if (index.first < index.second) {
		cout << index.first << ' ' << index.second;
	}
	else {
		cout << index.second << ' ' << index.first;
	}

	return 0;
}