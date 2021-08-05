#include<iostream>
using namespace std;
#include<string>

//string的构造函数
void test1()
{
	string s1; //默认构造

	const char* str = "hello world";
	string s2(str);

	cout << "s2=" << s2 << endl;

	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}