#include<iostream>
using namespace std;
#include<string>

//?ַ????Ƚ?

void test1()
{
	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)
	{
		cout << "str1 = str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}
}


int main()
{
	test1();

	system("pause");
	return 0;
}