#include<iostream>
#include<string>
using namespace std;

//�绰��
class Phone
{
public:
	Phone(string pName)
	{
		m_PName = pName;
		cout << "Phone ���캯������" << endl;
	}
	~Phone()
	{
		cout << "Phone ���캯������" << endl;
	}
	string m_PName;
};

//��Ա��
class Person
{
public:
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person ���캯������" << endl;
	}
	~Person()
	{
		cout << "Person ������������" << endl;
	}
	//����
	string m_Name;
	//�绰
	Phone m_Phone;
};

void test1()
{
	Person p("����", "iPhone");
	cout << p.m_Name << "ʹ��" << p.m_Phone.m_PName << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//�������������Ϊ�����Ա������ʱ�ȹ���������ٹ�������������˳��֮