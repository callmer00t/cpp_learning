#include<iostream>
using namespace std;

//Ĭ������£�c++���������ٸ�һ�������3������
//1. Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
//2. Ĭ�������������޲Σ�������Ϊ�գ�
//3. Ĭ�Ͽ������캯���������Խ���ֵ����

//���ù���
//����û������вι��캯����C++�����ṩĬ���޲ι��캯�������ǻ��ṩĬ�Ͽ������캯��
//����û����忽�����캯����C++�����ṩ�������캯��

class Person
{
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Person()
	{
		cout << "�޲ι��캯������" << endl;
	}

	//�вι��캯��
	Person(int a)
	{
		m_age = a;
		cout << "�вι��캯������" << endl;
	}
	Person(const Person& p)
	{
		m_age = p.m_age;
		cout << "�������캯������" << endl;

	}
	~Person()
	{
		cout << "������������" << endl;
	}
	int m_age;
};

//void test1()
//{
//	Person p1;
//	p1.m_age = 18;
//	Person p2(p1);
//	cout << "p2������Ϊ��" << p2.m_age << endl;
//}

void test2()
{
	Person p(28);
	Person p2(p);
	cout << "p2������Ϊ��" << p2.m_age << endl;
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}