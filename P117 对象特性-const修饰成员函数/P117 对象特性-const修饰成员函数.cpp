#include<iostream>
using namespace std;

//������
//�������ڲ������޸ĳ�Ա����
//��Ա��������ʱ��ӹؼ���mutable�������޸�
//


class Person
{
public:
	void showPerson() const //������
	{
		//m_A = 100; //���������ƺ������const��ʹ���Ϊ�������������޸ĳ�Ա����
		m_B = 100;
	}
	//const ���ε���thisָ��

	int m_A;
	mutable int m_B; //����������ڳ�������Ҳ�����޸ģ�ʹ�ùؼ��� mutable ����

	void func() //��ͨ����
	{

	}
};

void test1()
{
	Person p;
	p.showPerson();
}

//������
//������ֻ�ܵ��ó�����
void test2()
{
	const Person p;
	//p.m_A = 100; //����Ϊconst Person p �ǳ��������Բ����޸�
	p.m_B = 100; //mutable���εĶ�����޸�
	p.showPerson(); //��������Ե��ó�����
	//p.func(); //��������ֻ�ܵ��ó�����
	//��ͨ�����п����޸Ķ������ԣ�����func()��m_A=100; �����������в������޸Ķ�������ԣ����������������Ե�����ͨ�������������޸Ķ��������ˣ�����ֱ�ӹ涨������ֻ�ܵ��ó�����
}

int main()
{


	system("pause");
	return 0;
}