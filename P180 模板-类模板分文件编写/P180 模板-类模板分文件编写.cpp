#include<iostream>
using namespace std;

//#include<string>
//
//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "姓名：" << this->m_Name << endl;
//	cout << "年龄：" << this->m_Age << endl;
//}

//#include"Person.cpp" //解决方法1：直接包含cpp文件
#include"Person.hpp" //解决方法2：包含hpp文件

void test1()
{
	Person<string, int>p("Jerry", 18);
	p.showPerson();
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//问题：类模板中成员函数创建时机是在调用阶段，导致份文件编写时链接不到
//解决：
//1. 直接包含.cpp源文件
//2. 将声明和实现写到同一个文件中，后缀名为.hpp