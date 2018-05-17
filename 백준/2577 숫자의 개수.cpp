#include <iostream>
using namespace std;

int main() {
	int num1, num2, num3, sum;
	int arr[10] = { 0, };
	cin >> num1 >> num2 >> num3;
	// num의 범위는 100 <= num < 1000이므로
	// int의 양의 범위인 2^31-1보다 작을수밖에 없기에
	// int를 사용할수 있다.

	sum = num1 * num2 * num3;

	while (sum > 0) {
		++arr[sum % 10];
		sum /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << '\n';
	}

	return 0;
}