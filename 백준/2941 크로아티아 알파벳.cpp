#include <iostream>
#include <string>
using namespace std;

int main() {
	string cro[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	string str;
	int num = 0;
	bool check;

	cin >> str;

	for (int i = 0; i < str.length();) {
		check = true;
		for (auto &s : cro) {
			if (str.find(s, i) == i) {
				num++;
				i += s.length();
				check = false;
				break;
			}
		}
		if (check) {
			if (str[i] != '-' && str[i] != '=')
				num++;
			i++;
		}
	}

	cout << num << endl;
	return 0;
}