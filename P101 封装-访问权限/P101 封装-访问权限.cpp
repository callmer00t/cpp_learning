#include<iostream>
using namespace std;

class Person
{
public:
	string m_Name; //姓名

protected:
	string m_Car; //汽车

private:
	int m_Password; //密码

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

int main()
{
	Person p1;
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰"; //protected 类外不可访问
	//p1.m_Password = 654321; //private 类外不可访问

	system("pause");
	return 0;
}

//Public:		成员类内可以访问，类外可以访问
//Protected:	成员类内可以访问，类外不可以访问，子孙类可以访问父类的保护内容
//Private:	成员类内可以访问，类外不可以访问，子孙类不可以访问父类的私有内容