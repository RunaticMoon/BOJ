// http://bowbowbow.tistory.com/6 ³Ê¹« ¾î·Æ´Ù. ÀÌÇØ¾ÈµÊ
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> fail;
	vector<int> find;
	string str, check;

	getline(cin, str);
	getline(cin, check);
	//str = "ABC ABCDAB ABCDABCDABDE";
	//check = "ABCDABD";
	//str = "ABCDABCDABEE";
	//check = "ABCDABE";

	// make fail function
	int j = 0;
	fail.assign(check.length(), 0);
	for (int i = 1; i < check.length(); ++i) {
		while (j > 0 && check[i] != check[j])
			j = fail[j - 1];
		if (check[i] == check[j])
			fail[i] = ++j;
	}

	/*
	cout << "str   : " << str << endl;
	cout << "check : " << check << endl;

	cout << "fail : ";
	for (auto i : fail) {
	cout << i << ' ';
	}
	cout << endl;
	*/
	// check string compare
	j = 0;
	for (int i = 0; i < str.length(); i++) {
		while (j > 0 && str[i] != check[j]) {
			j = fail[j - 1];
		}
		if (str[i] == check[j]) {
			if (j == check.length() - 1) {
				find.push_back(i - check.length() + 1);
				j = fail[j];
			}
			else {
				j++;
			}
		}
	}
	//cout << "-----------------------------" << endl;
	//cout << "str   : " << str.substr(i, check.length()) << endl;
	//cout << "check : " << check << endl;
	//cout << "i : " << i << ", j : " << j << ", check[j] : " << check[j] << endl;
	//cout << "fail : " << fail[j] << ". new i : " << i << endl;

	cout << find.size() << endl;
	for (auto i : find) {
		cout << i + 1 << ' ';
	}
	//system("pause >> null");
	return 0;
}