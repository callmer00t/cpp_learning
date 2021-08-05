#include<iostream>
#include<string>
using namespace std;

template<class NameType, class AgeType=int> //可以在参数列表中添加默认参数（函数模板不允许这样使用）
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	NameType m_Name;
	AgeType m_Age;

	void showPerson()
	{
		cout << "name: " << this->m_Name << "age: " << this->m_Age << endl;
	}
};

//类模板没有自动类型推导的使用方式
void test1()
{
	//Person p("孙悟空", 1000); //错误，类模板无法自动类型推导
	Person<string, int>p("孙悟空", 1000); //正确，显式指定类型
	p.showPerson();
}

//类模板在模板参数列表中可以有默认参数
void test2()
{
	Person<string>p("猪八戒", 999); //显式指定类型时仅指定string，int使用了参数列表中的默认值
	p.showPerson();
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}

//主要区别
//1. 类模板没有自动类型推导的使用方式
//2. 类模板在模板参数列表中可以有默认参数