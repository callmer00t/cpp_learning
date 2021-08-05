#include<iostream>
using namespace std;
#include<string>

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "姓名：" << this->m_Name << "年龄：" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

//1. 指定传入类型
void printPerson1(Person<string, int>& p) //指定传入类型，把p的类型直接填进去，以引用的方式传递，此处Person<string, int>& p作为函数printPerson1()的形参
{
	p.showPerson(); //调用showPerson()函数
}

//2. 参数模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p) //将参数中的类型string, int模板化为T1, T2
{
	p.showPerson();
	cout << "T1 的类型为：" << typeid(T1).name() << endl; //显示模板中的T自动推导出的数据类型
	cout << "T2 的类型为：" << typeid(T2).name() << endl;
}

//3. 整个类模板化
template<class T>
void printPerson3(T &p) //将整个Person类模板化为T，编译器自动推导
{
	p.showPerson();
	cout << "T 的类型为：" << typeid(T).name() << endl;
}

void test1()
{
	Person<string, int>p("孙悟空", 100);
	printPerson1(p); //实参p传递给printPerson1()函数
}

void test2()
{
	Person<string, int>p("猪八戒", 99);
	printPerson2(p);
}

void test3()
{
	Person<string, int>p("唐僧", 30);
	printPerson3(p);
}

int main()
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}

//类模板实例化出对象，向函数传参的方式


