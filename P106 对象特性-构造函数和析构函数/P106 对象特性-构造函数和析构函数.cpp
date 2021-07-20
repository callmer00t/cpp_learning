#include<iostream>
using namespace std;

//构造函数
class Person
{
public: //注意要在public作用域，以便类外访问
	//1. 构造函数
	//没有返回值，不用写数据类型，函数名与类名相同，可以有参数，可以重载，创建对象时构造函数会自动调用，且只调用一次
	Person()
	{
		cout << "Person 构造函数的调用" << endl;
	}

	//2. 析构函数
	//没有返回值，不用写数据类型，函数名与类名相同，前面加~，没有参数，不能重载，对象销毁前析构函数会自动调用，且只调用一次
	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}
};

void test1()
{
	Person p; //局部变量，在栈区，test1执行完毕后会释放对象，所以自动调用析构函数
}

int main()
{
	//test1();
	Person p; //如果在main函数中创建对象，程序执行到此行时，对象不会被销毁，所以没有调用析构函数，执行结束后释放，会调用析构函数
	system("pause");
	return 0;
}