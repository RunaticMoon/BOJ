#include <iostream>
using namespace std;

int main() {
	// 모든 점수는 5의 배수이기 때문에 평균점수는 항상 정수
	int score, sum = 0;

	for (int i = 0; i < 5; ++i) {
		cin >> score;
		sum += (score > 40) ? score : 40;
	}

	cout << sum / 5;

	return 0;
}