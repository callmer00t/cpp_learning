#include<iostream>
using namespace std;

//系列视频中缺失此部分，单独观看 https://www.bilibili.com/video/BV1bz4y1S7gs

//静态成员变量

class Person
{
public:
	//1. 所有对象共享同一份数据
	//2. 在编译阶段分配内存
	//3. 类内声明，类外初始化
	static int m_A;

	//静态成员变量也具有访问权限
private:
	static int m_B; //私有作用域，类外无法访问
};

int Person::m_A = 100;
int Person::m_B = 200;

void test1()
{
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test2()
{
	//静态成员变量不属于某个对象，所有对象共享，因此静态成员变量有两种访问方式
	//1. 通过对象访问
	Person p;
	cout << p.m_A << endl;
	//2. 通过类名访问
	cout << Person::m_A << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}