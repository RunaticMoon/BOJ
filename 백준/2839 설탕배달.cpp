#include <iostream>
using namespace std;

int main() {
	int suger, num = 0;

	cin >> suger;

	for (int i = suger / 5; i >= 0; --i) {
		for (int j = 0; j <= suger / 3; ++j) {
			if (suger == i * 5 + j * 3) {
				suger = 0;
				num = i + j;
				break;
			}
		}
		if (suger == 0)
			break;
	}
	if (suger != 0)
		num = -1;

	cout << num << endl;

	return 0;
}