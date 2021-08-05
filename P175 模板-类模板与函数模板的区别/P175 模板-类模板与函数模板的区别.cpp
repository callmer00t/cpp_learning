#include<iostream>
#include<string>
using namespace std;

template<class NameType, class AgeType=int> //�����ڲ����б������Ĭ�ϲ���������ģ�岻��������ʹ�ã�
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

//��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test1()
{
	//Person p("�����", 1000); //������ģ���޷��Զ������Ƶ�
	Person<string, int>p("�����", 1000); //��ȷ����ʽָ������
	p.showPerson();
}

//��ģ����ģ������б��п�����Ĭ�ϲ���
void test2()
{
	Person<string>p("��˽�", 999); //��ʽָ������ʱ��ָ��string��intʹ���˲����б��е�Ĭ��ֵ
	p.showPerson();
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}

//��Ҫ����
//1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//2. ��ģ����ģ������б��п�����Ĭ�ϲ���