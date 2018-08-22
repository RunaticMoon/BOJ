#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int number;
	double distance;

	cin >> number;

	int *array = new int[number * 6];

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> array[i * 6 + j];
		}
	}

	for (int i = 0; i < number; i++) {
		distance = sqrt(pow(array[i * 6 + 0] - array[i * 6 + 3], 2) + pow(array[i * 6 + 1] - array[i * 6 + 4], 2));

		if (array[i * 6 + 0] == array[i * 6 + 3] && array[i * 6 + 1] == array[i * 6 + 4] && array[i * 6 + 2] == array[i * 6 + 5]) {
			cout << -1 << endl;
		}
		else if (abs(array[i * 6 + 2] - array[i * 6 + 5]) < distance && distance < array[i * 6 + 2] + array[i * 6 + 5]) {
			cout << 2 << endl;
		}
		else if (distance == array[i * 6 + 2] + array[i * 6 + 5] || distance == abs(array[i * 6 + 2] - array[i * 6 + 5])) {
			cout << 1 << endl;
		}
		else if (distance > array[i * 6 + 2] + array[i * 6 + 5] || distance < abs(array[i * 6 + 2] - array[i * 6 + 5])) {
			cout << 0 << endl;
		}
	}
	return 0;
}