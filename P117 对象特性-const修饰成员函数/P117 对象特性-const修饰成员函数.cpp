#include<iostream>
using namespace std;

//常函数
//常函数内不可以修改成员属性
//成员属性声明时添加关键字mutable，可以修改
//


class Person
{
public:
	void showPerson() const //常函数
	{
		//m_A = 100; //函数体名称后面添加const，使其成为常函数，不能修改成员属性
		m_B = 100;
	}
	//const 修饰的是this指针

	int m_A;
	mutable int m_B; //特殊变量，在常函数中也可以修改，使用关键字 mutable 修饰

	void func() //普通函数
	{

	}
};

void test1()
{
	Person p;
	p.showPerson();
}

//常对象
//常对象只能调用常函数
void test2()
{
	const Person p;
	//p.m_A = 100; //错，因为const Person p 是常对象，属性不可修改
	p.m_B = 100; //mutable修饰的对象可修改
	p.showPerson(); //常对象可以调用常函数
	//p.func(); //错，常对象只能调用常函数
	//普通函数中可以修改对象属性，例如func()中m_A=100; ，但常对象中不允许修改对象的属性，所以如果常对象可以调用普通函数，即可以修改对象属性了，所以直接规定常对象只能调用常函数
}

int main()
{


	system("pause");
	return 0;
}