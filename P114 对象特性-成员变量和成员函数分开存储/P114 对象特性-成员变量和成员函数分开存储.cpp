#include<iostream>
using namespace std;

//成员变量和成员函数分开存储
class Person
{
	int m_A; //非静态成员变量，属于类的对象
	static int m_B; //静态成员变量，不属于类的对象
	void func()
	{

	} //非静态成员函数，不属于类的对象
	static void func2()
	{

	} //静态成员函数，不属于类的对象
};
int Person::m_B = 0;

void test1()
{
	Person p; //空对象占用内存空间为：1
	cout << "size of p=" << sizeof(p) << endl;
}

void test2()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}