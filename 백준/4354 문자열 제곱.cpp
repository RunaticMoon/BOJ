#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
int fail[1000002];
int result;

/*
	fail[len] : 접두사 = 접미사인 index + 1
	len - fail[len] : 문자열에서 반복되는 부분문자열의 최소 길이
	len % (len - fail[len]) == 0 : 부분문자열로만 이루어진 문자열
	len % (len - fail[len]) != 0 : 문자열 중간에 다른 문자가 끼어있음
	len - fail[len] > len / 2 : 부분문자열이 문자열의 모든 부분을 차지하고 있지 않음
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (getline(cin, str), str[0] != '.') {
		int len = str.size();
		memset(fail, 0, sizeof(fail));

		// 실패함수 구하기
		for (int i = 1, j = 0; i < len; i++) {
			while (j > 0 && str[i] != str[j]) j = fail[j - 1];
			if (str[i] == str[j]) fail[i] = ++j;
		}

		int flen = fail[len - 1];
		// TC가 바뀌었나봄 (옛날 코드에서는 flen == 0만 체크하던데
		// 문자열 중간에 다른 문자가 끼어있어도 안되는 조건을 추가해야됨
		if (flen == 0 || flen % (len - flen) != 0) result = 1;
		else result = len / (len - flen);

		cout << result << "\n";
	}

	return 0;
}