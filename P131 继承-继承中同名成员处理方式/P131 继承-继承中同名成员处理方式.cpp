#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		m_A = 100; //�����еĳ�Ա����
	}

	//�����еĳ�Ա����
	void func()
	{
		cout << "Base �е� func() ��������" << endl;
	}

	//�����еĺ�������
	void func(int a)
	{
		cout << "Base �е� func(int a) ��������" << endl;
	}

	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200; //�븸���еĳ�Աͬ��
	}

	//�����еĳ�Ա����
	void func()
	{
		cout << "Son �е� func() ��������" << endl;
	}
	int m_A;
};

//ͬ����Ա����
void test1()
{
	Son s;
	cout << "Son m_A = " << s.m_A << endl; //ͬ����Ա��Ĭ��Ϊ�����еĳ�Ա����
	cout << "Base m_A = " << s.Base::m_A << endl; //ͨ����s.������������򣬷��ʴӸ����м̳е�ͬ����Ա����
}

//ͬ����Ա����
void test2()
{
	Son s;
	s.func(); //ͬ����Ա������Ĭ�ϵ��������еĳ�Ա����
	s.Base::func(); //ͨ����s.������������򣬷��ʴӸ����м̳е�ͬ����Ա����
	s.Base::func(100); //���ø����еĺ�������
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}