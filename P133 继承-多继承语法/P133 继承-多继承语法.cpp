#include<iostream>
using namespace std;

//C++����һ����̳ж����
//�﷨��class ����: �̳з�ʽ ����1, �̳з�ʽ ����2����
//��̳п���������������ͬ����Ա���֣���Ҫʹ������������

class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
		m_B = 200;
	}
	int m_A;
	int m_B;
};

class Son :public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};

void test1()
{
	Son s;
	cout << "size of Son = " << sizeof(s) << endl;
	cout << "Base1 m_A = " << s.Son::Base1::m_A << endl;
	cout << "Base2 m_A = " << s.Son::Base2::m_A << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}