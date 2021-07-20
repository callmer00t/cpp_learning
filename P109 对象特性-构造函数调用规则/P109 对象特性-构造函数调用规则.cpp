#include<iostream>
using namespace std;

//默认情况下，c++编译器至少给一个类添加3个函数
//1. 默认构造函数（无参，函数体为空）
//2. 默认析构函数（无参，函数体为空）
//3. 默认拷贝构造函数，对属性进行值拷贝

//调用规则：
//如果用户定义有参构造函数，C++不再提供默认无参构造函数，但是会提供默认拷贝构造函数
//如果用户定义拷贝构造函数，C++不再提供其他构造函数

class Person
{
public:
	//无参（默认）构造函数
	Person()
	{
		cout << "无参构造函数调用" << endl;
	}

	//有参构造函数
	Person(int a)
	{
		m_age = a;
		cout << "有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "拷贝构造函数调用" << endl;

	}
	~Person()
	{
		cout << "析构函数调用" << endl;
	}
	int m_age;
};

//void test1()
//{
//	Person p1;
//	p1.m_age = 18;
//	Person p2(p1);
//	cout << "p2的年龄为：" << p2.m_age << endl;
//}

void test2()
{
	Person p(28);
	Person p2(p);
	cout << "p2的年龄为：" << p2.m_age << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}