#include <iostream>
using namespace std;

int main() {
	int month, day, days = 0;
	char week[][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int monthDay[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> month >> day;

	for (int i = 0; i < month; ++i) {
		if ((i + 1) == month)
			days += day;
		else
			days += monthDay[i];
	}

	cout << week[days % 7];


	return 0;
}