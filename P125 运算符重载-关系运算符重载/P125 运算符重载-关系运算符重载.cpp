#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//���ع�ϵ�����==
	bool operator==(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	//���ع�ϵ�����!=
	bool operator!=(Person& p)
	{
		if (this->m_Name != p.m_Name || this->m_Age != p.m_Age)
		{
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};

void test1()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);

	if (p1 == p2)
	{
		cout << "p1 �� p2 ����ͬ��" << endl;
	}
	else
	{
		cout << "p1 �� p2 �ǲ�ͬ��" << endl;
	}
	if (p1 != p2)
	{
		cout << "p1 �� p2 �ǲ�ͬ��" << endl;
	}
	else
	{
		cout << "p1 �� p2 ����ͬ��" << endl;
	}
}

int main()
{
	test1();

	system("pause");
	return 0;
}