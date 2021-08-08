#include<iostream>
using namespace std;
#include<string>

//字符串查找和替换

//查找
void test1()
{
	string str1 = "abcdefg";
	int pos = str1.find("de");
	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	pos = str1.rfind("fg");
	cout << "pos = " << pos << endl; //rfind从右向左查
}//索引从0开始，找不到返回-1

//替换
void test2()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111"); //第一个参数是从几号索引开始替换，第二个参数是替换多少位，第三个参数是替换为什么字符
	cout << "str1 = " << str1 << endl;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}