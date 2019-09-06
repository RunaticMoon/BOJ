#include <iostream>
using namespace std;

unsigned char ch[] = { 0xEF, 0xBF, 0xBD, 0 };

int main() {
	cout << ch;

	return 0;
}

/*
	힌트에서 占쏙옙을 제거시

	이문제는예제를채점하지않습니다.
	데이터는한개입니다
	입력을받을필요는없다

	라는 문구가 보인다.
	여기서 占쏙옙을 EUC-KR로 인코딩시 
	EFBF BDEF BFBD가 되고
	EFBFBD EFBFBD 이렇게 중복된 데이터가 되는데
	힌트에 데이터는 한개라고 했기에 하나를 제거하면
	EFBFBD를 UTF-8로 인코딩한 �가 정답이다.

	+ 제출을 Text로 하면 � 하나가 정답이지만
	c/c++은 각 0xEF, 0xBF, 0xBD, 0 를 출력해 문자열로 만들어야 한다.
*/
