#include<iostream>
using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:
	static void func()
	{
		m_A = 100; //静态成员函数可以访问静态成员变量
		//m_B = 100; //报错，不能访问非静态成员变量
		cout << "static void func() 调用" << endl;
	}

	static int m_A; //静态成员变量
	int m_B; //非静态成员变量
};

int Person::m_A = 0; //静态成员变量在类内声明，必须在类外初始化

void test1()
{
	//1. 通过对象访问
	Person p;
	p.func();
	
	//2. 通过类名访问
	Person::func();
}

int main()
{
	test1();

	system("pause");
	return 0;
}