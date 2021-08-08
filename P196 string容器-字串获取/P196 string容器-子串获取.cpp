#include<iostream>
using namespace std;
#include<string>

//子串

void test1()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3); //第一个参数是从X索引开始截取字串，第二个参数是截取Y位字符
	cout << "subStr = " << subStr << endl;
}

//实用案例
void test2()
{
	//从邮箱地址中获取用户名信息
	string email = "zhangsan@abc.com";
	int pos = email.find('@');
	string username = email.substr(0, pos);
	cout << "username = " << username << endl;
}


int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}