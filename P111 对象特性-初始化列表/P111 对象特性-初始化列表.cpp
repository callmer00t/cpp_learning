#include<iostream>
using namespace std;

//���ã���ʼ������
//�﷨�����캯��() :����1(ֵ1), ����2(ֵ2), ...{}

class Person
{
public:
	int m_A;
	int m_B;
	int m_C;

	////��ͳ��ʼ������
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//���ó�ʼ���б��ʼ��
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{

	}
};

void test1()
{
	Person p(10, 20, 30);
	cout << "m_A=" << p.m_A << endl;
	cout << "m_B=" << p.m_B << endl;
	cout << "m_C=" << p.m_C << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}