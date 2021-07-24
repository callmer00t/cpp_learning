#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		m_A = 100; //父类中的成员变量
	}

	//父类中的成员函数
	void func()
	{
		cout << "Base 中的 func() 函数调用" << endl;
	}

	//父类中的函数重载
	void func(int a)
	{
		cout << "Base 中的 func(int a) 函数调用" << endl;
	}

	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200; //与父类中的成员同名
	}

	//子类中的成员函数
	void func()
	{
		cout << "Son 中的 func() 函数调用" << endl;
	}
	int m_A;
};

//同名成员属性
void test1()
{
	Son s;
	cout << "Son m_A = " << s.m_A << endl; //同名成员，默认为子类中的成员属性
	cout << "Base m_A = " << s.Base::m_A << endl; //通过在s.后面添加作用域，访问从父类中继承的同名成员属性
}

//同名成员函数
void test2()
{
	Son s;
	s.func(); //同名成员函数，默认调用子类中的成员函数
	s.Base::func(); //通过在s.后面添加作用域，访问从父类中继承的同名成员函数
	s.Base::func(100); //调用父类中的函数重载
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}