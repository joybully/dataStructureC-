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
//terminal���� pstr+500,10���� ������ pstr�� value Ȯ�� ����

	system("pause");
	return 0 ;
}
