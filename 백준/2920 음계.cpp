#include <iostream>
using namespace std;

int main() {
	/*
	c d e f g a b C
	1 2 3 4 5 6 7 8
	1~8 : ascending
	8~1 : descending
	else : mixed
	*/

	int arr[8], pnum;

	for (int i = 0; i < 8; ++i)
		cin >> arr[i];

	pnum = arr[0];
	for (int i = 1; i < 8; ++i) {
		if (arr[i] - pnum == 1) {
			pnum = arr[i];
			if (7 == i)
				cout << "ascending";
		}
		else if (arr[i] - pnum == -1) {
			pnum = arr[i];
			if (7 == i)
				cout << "descending";
		}
		else {
			cout << "mixed";
			break;
		}
	}


	return 0;
}