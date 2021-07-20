#include<iostream>
using namespace std;

//作用：初始化属性
//语法：构造函数() :属性1(值1), 属性2(值2), ...{}

class Person
{
public:
	int m_A;
	int m_B;
	int m_C;

	////传统初始化操作
	//Person(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//利用初始化列表初始化
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