#include<iostream>
using namespace std;

class Base
{
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
	static int m_A; //��̬��Ա���ԣ���������
};

int Base::m_A = 100; //�����ʼ��

class Son :public Base
{
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Son - static void func(int a)" << endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//ͬ����̬��Ա����
void test1()
{
	//1. ͨ���������
	cout << "ͨ��������ʣ�" << endl;
	Son s;
	cout << "Son m_A = " << s.m_A << endl; //Ĭ������
	cout << "Base m_A = " << s.Base::m_A << endl; //Ĭ������

	//2. ͨ����������
	cout << "ͨ���������ʣ�" << endl;
	cout << "Son m_A = " << Son::m_A << endl;
	cout << "Base m_A = " << Son::Base::m_A << endl; //ע����Base::m_A������Base::m_A��ֱ�ӷ���Base��
	//��һ��::����ͨ��������ʽ���ʣ��ڶ���::��ʾ���ʸ���������
}

//ͬ����̬��Ա����
void test2()
{
	//1. ͨ���������
	cout << "ͨ��������ʣ�" << endl;
	Son s;
	s.func();
	s.Base::func();

	//2. ͨ����������
	cout << "ͨ���������ʣ�" << endl;
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}