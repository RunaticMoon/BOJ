#include <iostream>
using namespace std;

int main() {
	int num1, num2, num3, sum;
	int arr[10] = { 0, };
	cin >> num1 >> num2 >> num3;
	// num�� ������ 100 <= num < 1000�̹Ƿ�
	// int�� ���� ������ 2^31-1���� �������ۿ� ���⿡
	// int�� ����Ҽ� �ִ�.

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