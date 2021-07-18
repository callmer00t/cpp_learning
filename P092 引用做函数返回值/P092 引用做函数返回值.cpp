#include<iostream>
using namespace std;

int& test1()
{
	int a = 10; //局部变量，存放在栈区
	return a;
}

int& test2()
{
	static int a = 10; //静态变量，存放在全局区
	return a;
}

int main()
{
	int& ref1 = test1();
	cout << "ref1=" << ref1<< endl; //第一次返回正确的值，因为编译器做了保留
	cout << "ref1=" << ref1 << endl; //第二次返回随机值，因为内存已经被释放

	int& ref2 = test2();
	cout << "ref2=" << ref2 << endl; //第一次返回正确的值

	test2() = 1000; //函数调用作为左值
	cout << "ref2=" << ref2 << endl; //第二次返回正确的值

	system("pause");
	return 0;
}

/*
注意事项
1. 不要返回局部变量的引用
2. 函数的调用可以作为左值
*/