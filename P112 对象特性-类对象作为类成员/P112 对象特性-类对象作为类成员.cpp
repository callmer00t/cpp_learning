#include<iostream>
#include<string>
using namespace std;

//电话类
class Phone
{
public:
	Phone(string pName)
	{
		m_PName = pName;
		cout << "Phone 构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "Phone 构造函数调用" << endl;
	}
	string m_PName;
};

//人员类
class Person
{
public:
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person 构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}
	//姓名
	string m_Name;
	//电话
	Phone m_Phone;
};

void test1()
{
	Person p("张三", "iPhone");
	cout << p.m_Name << "使用" << p.m_Phone.m_PName << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//当其他类对象作为本类成员，构造时先构造类对象，再构造自身，析构的顺序反之