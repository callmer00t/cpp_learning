#include<iostream>
using namespace std;

class Base
{
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
	static int m_A; //静态成员属性，类内声明
};

int Base::m_A = 100; //类外初始化

class Son :public Base
{
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Son - static void func(int a)" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//同名静态成员属性
void test1()
{
	//1. 通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	cout << "Son m_A = " << s.m_A << endl; //默认子类
	cout << "Base m_A = " << s.Base::m_A << endl; //默认子类

	//2. 通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son m_A = " << Son::m_A << endl;
	cout << "Base m_A = " << Son::Base::m_A << endl; //注意与Base::m_A的区别，Base::m_A是直接访问Base类
	//第一个::代表通过类名方式访问，第二个::表示访问父类作用域
}

//同名静态成员函数
void test2()
{
	//1. 通过对象访问
	cout << "通过对象访问：" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2. 通过类名访问
	cout << "通过类名访问：" << endl;
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}