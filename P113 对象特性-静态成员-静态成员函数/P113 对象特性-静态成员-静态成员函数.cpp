#include<iostream>
using namespace std;

//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

class Person
{
public:
	static void func()
	{
		m_A = 100; //��̬��Ա�������Է��ʾ�̬��Ա����
		//m_B = 100; //�������ܷ��ʷǾ�̬��Ա����
		cout << "static void func() ����" << endl;
	}

	static int m_A; //��̬��Ա����
	int m_B; //�Ǿ�̬��Ա����
};

int Person::m_A = 0; //��̬��Ա���������������������������ʼ��

void test1()
{
	//1. ͨ���������
	Person p;
	p.func();
	
	//2. ͨ����������
	Person::func();
}

int main()
{
	test1();

	system("pause");
	return 0;
}