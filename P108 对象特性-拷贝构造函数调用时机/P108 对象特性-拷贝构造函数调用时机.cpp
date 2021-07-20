#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person 默认构造函数调用" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "Person 有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "Person 拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person 析构函数调用" << endl;
	}
	int m_Age;
};

//使用一个已创建完毕的对象初始化一个新对象
void test1()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2 的年龄为：" << p2.m_Age << endl;
}

//以值传递的方式给函数参数传值
void doWork1(Person p) //形参p
{

}
void test2()
{
	Person p;
	doWork1(p); //实参p
}

//以值的方式返回局部对象
Person doWork2()
{
	Person p3;
	cout << (int*)&p3 << endl; //p3的地址
	return p3; //p3是一个局部对象，return时，会拷贝一个新的对象出来传递到函数外
}
void test3()
{
	Person p = doWork2();
	cout << (int*)&p << endl; //p的地址，与p3不同
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}