#include <iostream>

using namespace std;

int main()
{
	char str[1000];
	char* pstr = new char[1000];
	cin >> str;
	cin >> pstr;
	cout << str<<endl<<"hello, world" << endl;

	for (int i = 0; i < 1000000; i++)
		cout << str << endl;

	cout << pstr << endl;
//terminal에서 pstr+500,10으로 적으면 pstr의 value 확인 가능

	system("pause");
	return 0 ;
}
