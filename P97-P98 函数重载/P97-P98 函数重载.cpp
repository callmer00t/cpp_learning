#include<iostream>
using namespace std;

void func()
{
	cout << "func() 的调用" << endl;
}

void func(int a) //函数参数个数不同
{
	cout << "func(int a) 的调用" << endl;
}

void func(double a) //函数类型不同
{
	cout << "func(double a) 的调用" << endl;
}

void func(double a, int b) //函数参数顺序不同
{
	cout << "func(double a, int b) 的调用" << endl;
}

void func(int a, double b) //函数参数顺序不同
{
	cout << "func(int a, double b) 的调用" << endl;
}

//引用作为重载条件
void func2(int& a)
{
	cout << "func2(int& a) 的调用" << endl;
}

void func2(const int& a) //常引用与普通引用是不同数据类型
{
	cout << "func2(const int& a) 的调用" << endl;
}

//函数重载遇到默认参数
void func3(int a, int b = 10)
{
	cout << "func3(int a, int b) 的调用" << endl;
}

void func3(int a)
{
	cout << "func3(int a) 的调用" << endl;
}

int main()
{
	func(); //调用 func 函数
	func(10); //调用 func(int a) 函数
	func(3.14); //调用 func(double a) 函数
	func(3.14, 10); //调用 func(double a, int b) 函数
	func(10, 3.14); //调用 func(int a, double b) 函数

	//引用作为重载条件
	int a = 10;
	func2(a); //a是变量，调用普通引用函数

	func2(10); //10是常量，调用常引用函数

	//函数重载遇到默认参数
	//func3(10); //出现二义性，由于第一个func3的b参数具有默认值，也可以调用

	system("pause");
	return 0;
}


//作用：函数名可以相同，提高复用性
//条件：
//	1. 同一个作用域下
//	2. 函数名称相同
//	3. 函数参数 类型不同 或 个数不同 或 顺序不同
//注意：函数的返回值不可以作为函数重载的条件

//注意事项：
//	1. 引用作为重载条件
//	2. 函数重载遇到函数默认参数