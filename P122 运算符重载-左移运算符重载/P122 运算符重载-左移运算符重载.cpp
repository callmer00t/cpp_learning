#include<iostream>
using namespace std;

//左移运算符重载

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person(int c, int d)
	{
		m_C = c;
		m_D = d;
	}
	int m_A;
	int m_B;
private:
	int m_C;
	int m_D;
};

//只能使用全局函数重载左移运算符
ostream &operator<<(ostream& cout, Person& p) //本质 operator<<(cout, p) 简化 cout<<p
{
	cout << "m_A=" << p.m_A << "\t" << "m_B=" << p.m_B;
	cout << "m_C=" << p.m_C << "\t" << "m_D=" << p.m_D;
	return cout;
}

void test1()
{
	Person p1(10, 10);
	p1.m_A = 10;
	p1.m_B = 10;
	cout << p1 << "\t" << "hello world" << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}