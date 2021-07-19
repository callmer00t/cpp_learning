#include<iostream>
using namespace std;

class Person
{
private:
	string m_Name; //姓名 可读写
	int m_Age; //年龄 可读写，范围0-150
	string m_Lover; //情人 只写

public:
	void setName(string name)
	{
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "年龄有误" << endl;
			return;
		}
		m_Age = age;
	}
	int getAge()
	{
		//m_Age = 0; //初始化年龄
		return m_Age;
	}
	void setLover(string lover)
	{
		m_Lover = lover;
	}
};

int main()
{
	Person p;
	p.setName("张三");
	cout << "姓名：" << p.getName() << endl;
	p.setLover("苍井");
	p.setAge(20);
	cout << "年龄：" << p.getAge() << endl;

	system("pause");
	return 0;
}

//成员属性设置为私有，优点：
//1. 自己控制读写权限
//2. 写操作时便于检测数据有效性