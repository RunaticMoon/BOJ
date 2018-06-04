#include <iostream>
#include <algorithm>
using namespace std;

int minTemp[3], maxTemp[3], minArr[3], maxArr[3];

int main() {
	int number;

	cin >> number;

	for (int i = 0; i < number; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> maxTemp[j];
			minTemp[j] = maxTemp[j];
		}

		maxTemp[0] += *max_element(maxArr, maxArr + 2);
		maxTemp[1] += *max_element(maxArr, maxArr + 3);
		maxTemp[2] += *max_element(maxArr + 1, maxArr + 3);

		minTemp[0] += *min_element(minArr, minArr + 2);
		minTemp[1] += *min_element(minArr, minArr + 3);
		minTemp[2] += *min_element(minArr + 1, minArr + 3);

		for (int j = 0; j < 3; ++j) {
			maxArr[j] = maxTemp[j];
			minArr[j] = minTemp[j];
		}
	}

	cout << *max_element(maxArr, maxArr + 3) << ' ' << *min_element(minArr, minArr + 3);

	return 0;
}