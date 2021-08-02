#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//姓名
	string m_Name;
	//年龄
	int m_Age;
};

//对比两个数据是否相同
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//具体化的Person的版本
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//使用template<>开头，表示是模板的重载，将参数列表中的T类型替换为Person，函数实现中写Person类型的对比逻辑

void test1()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}

void test2()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}
//test2会报错，语法没有错误，但运行时，当将自定义数据类型Person推导到T，编译器会不知道如何比较自定义的数据类型Person
//解决方法1：运算符重载
//解决方法2：重载模板

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}