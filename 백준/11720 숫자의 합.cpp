#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int limit, sum = 0;
	char array[100];

	cin >> limit;
	scanf("%s", array);

	for (int i = limit - 1; i >= 0; --i) {
		sum += array[i] - '0';
	}
	cout << sum;

	return 0;
}