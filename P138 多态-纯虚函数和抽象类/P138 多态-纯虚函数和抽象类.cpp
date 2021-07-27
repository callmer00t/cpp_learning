#include<iostream>
using namespace std;

class Base
{
public:
	//类中只要有纯虚函数，则成为抽象类，无法实例化对象，子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0; //纯虚函数，语法：virtual（虚函数）后面加=0

};

class Son :public Base
{
public:
	virtual void func()
	{

	};
};

void test1()
{
	//Base b; //抽象类无法实例化对象
	//new Base; //抽象类无法实例化对象
	Son s; //子类必须重写父类中的纯虚函数，否则无法实例化对象
}

int main()
{


	system("pause");
	return 0;
}