#include<iostream>
using namespace std;
#include<string>

//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	void showPerson()
//	{
//		cout << "姓名：" << this->m_Name << endl;
//		cout << "年龄：" << this->m_Age << endl;
//	}
//	T1 m_Name;
//	T2 m_Age;
//};
////类内实现

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age); //类内仅写声明，类外实现
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}
	void showPerson(); //类内仅写声明，类外实现
	//{
	//	cout << "姓名：" << this->m_Name << endl;
	//	cout << "年龄：" << this->m_Age << endl;
	//}
	T1 m_Name;
	T2 m_Age;
};

//构造函数的类外实现
template<class T1,class T2> //添加template告知编译器T1和T2参数类型
Person<T1, T2>::Person(T1 name, T2 age) //添加作用域Person，添加<T1, T2>表示是类模板成员函数的类外实现，如果不加<T1, T2>则是普通成员函数的类外实现
{
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名：" << this->m_Name << endl;
	cout << "年龄：" << this->m_Age << endl;
}

void test1()
{
	Person<string, int>p("Tom", 20);
	p.showPerson();
}


int main()
{
	test1();

	system("pause");
	return 0;
}