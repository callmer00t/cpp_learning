#include<iostream>
#include<string>
using namespace std;

template<class NameType, class AgeType>

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
		cout << "name: " << this->m_Name << endl;
		cout << "age: " << this->m_Age << endl;
	}
};

void test1()
{
	Person<string, int>p1("ËïÎò¿Õ", 999);
	p1.showPerson();
}

int main()
{
	test1();

	system("pause");
	return 0;
}