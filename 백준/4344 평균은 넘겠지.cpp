#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int C, student_number, score, sum, n;
	double average;
	int *arr;

	cin >> C;

	for (int test_case = 0; test_case < C; test_case++) {
		cin >> student_number;

		arr = new int[student_number];

		sum = 0;
		for (int i = 0; i < student_number; ++i) {
			cin >> score;
			arr[i] = score;
			sum += score;
		}
		average = (double)sum / student_number;

		n = 0;
		for (int i = 0; i < student_number; ++i) {
			if (arr[i] > average)
				++n;
		}

		cout << fixed << setprecision(3);
		cout << (double)n / student_number * 100 << "%\n";

		delete[] arr;
	}

	return 0;
}