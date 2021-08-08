#include<iostream>
using namespace std;
#include<string>

//字符插入和删除

void test1()
{
	string str = "hello";
	str.insert(1, "111"); //第一个参数是从X个索引位置插入，第二个参数是插入的内容
	cout << "str = " << str << endl;

	str.erase(1, 3); //第一个参数是从X索引位置开始删除，第二个参数是删除X个字符
	cout << "str = " << str << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}