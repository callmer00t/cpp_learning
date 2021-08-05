#include<iostream>
using namespace std;

#include<string>

template<class T1, class T2>
class Person;
//提前让编译器知道Person类，并且是一个类模板

//全局函数类外实现
template<class T1, class T2> //需要添加模板
void printPerson2(Person<T1, T2> p) //全局函数，无需加作用域
{
	cout << "类外实现" << endl;
	cout << "姓名：" << p.m_Name << endl;
	cout << "年龄：" << p.m_Age << endl;
}
//这是函数模板的类外实现
//提前让编译器知道printPerson2函数

template<class T1,class T2>
class Person
{
	//全局函数类内实现
	friend void printPerson1(Person<T1, T2> p) //将全局函数设置为友元，使其可以访问类内的私有成员
	{
		cout << "姓名：" << p.m_Name << endl;
		cout << "年龄：" << p.m_Age << endl;
	}
	//friend void printPerson2(Person<T1, T2> p); //类外实现，类内仅写声明
	//错误，这是普通函数的类内声明
	friend void printPerson2<>(Person<T1, T2> p);
	//加空模板参数列表，表示这是函数模板的类内声明

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

void test1()
{
	Person<string, int>p("Tom", 20);
	printPerson1(p);
}

void test2()
{
	Person<string, int>p("Jerry", 30);
	printPerson2(p);
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}