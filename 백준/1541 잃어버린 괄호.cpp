#include <iostream>
#include <string>
using namespace std;

const int MAX = 5e1 + 1;

int sum;
string str;
size_t sz;
bool flag = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	while (!str.empty()) {
		if(flag) sum -= stoi(str, &sz);
		else sum += stoi(str, &sz);

		if (!flag && str[sz] == '-')
			flag = true;

		if (sz == str.length()) break;

		str = str.substr(sz + 1);
	}
	
	cout << sum;

	return 0;
}
