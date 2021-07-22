#include<iostream>
using namespace std;

//this指针用途：

//1. 解决名称冲突
class Person
{
public:
	Person(int age)
	{
		this->age = age; //如果不加this，编译器认为 Person 构造函数内的三个age是同一个对象，与下方的成员变量age不同，所以调用时未能将18传给成员变量age
	}
	int age;

	Person& PersonAddAge(Person &p) //如果返回的不是引用，而是值，输出结果为20，因为会调用拷贝构造函数复制一份新的对象出来
	{
		this->age += p.age;
		return *this;
		//this指向p2的指针，*this指向p2对象本体
	}
};
//更好的解决办法是使用良好的编码规范，成员变量使用单独的名称，例如m_Age


void test1()
{
	Person p1(18);
	cout << "p1 的年龄为：" << p1.age << endl;
}

//2. 返回对象本身
void test2()
{
	Person p1(10);
	Person p2(10);

	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2 的年龄为：" << p2.age << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}