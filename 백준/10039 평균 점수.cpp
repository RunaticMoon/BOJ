#include <iostream>
using namespace std;

int main() {
	// ��� ������ 5�� ����̱� ������ ��������� �׻� ����
	int score, sum = 0;

	for (int i = 0; i < 5; ++i) {
		cin >> score;
		sum += (score > 40) ? score : 40;
	}

	cout << sum / 5;

	return 0;
}