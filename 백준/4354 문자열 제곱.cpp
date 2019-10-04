#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
int fail[1000002];
int result;

/*
	fail[len] : ���λ� = ���̻��� index + 1
	len - fail[len] : ���ڿ����� �ݺ��Ǵ� �κй��ڿ��� �ּ� ����
	len % (len - fail[len]) == 0 : �κй��ڿ��θ� �̷���� ���ڿ�
	len % (len - fail[len]) != 0 : ���ڿ� �߰��� �ٸ� ���ڰ� ��������
	len - fail[len] > len / 2 : �κй��ڿ��� ���ڿ��� ��� �κ��� �����ϰ� ���� ����
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (getline(cin, str), str[0] != '.') {
		int len = str.size();
		memset(fail, 0, sizeof(fail));

		// �����Լ� ���ϱ�
		for (int i = 1, j = 0; i < len; i++) {
			while (j > 0 && str[i] != str[j]) j = fail[j - 1];
			if (str[i] == str[j]) fail[i] = ++j;
		}

		int flen = fail[len - 1];
		// TC�� �ٲ������ (���� �ڵ忡���� flen == 0�� üũ�ϴ���
		// ���ڿ� �߰��� �ٸ� ���ڰ� �����־ �ȵǴ� ������ �߰��ؾߵ�
		if (flen == 0 || flen % (len - flen) != 0) result = 1;
		else result = len / (len - flen);

		cout << result << "\n";
	}

	return 0;
}