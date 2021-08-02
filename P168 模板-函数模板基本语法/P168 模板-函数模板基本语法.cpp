#include<iostream>
using namespace std;

//模板语法：
//template<typename T>
//函数声明或定义

//两个整型交换函数
template<typename T> //声明一个模板，表明T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//自动类型推导
void test1()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

void test2()
{
	double c = 1.1;
	double d = 2.2;
	mySwap(c, d);
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;
}

//显式指定类型
void test3()
{
	int e = 10;
	int f = 20;
	mySwap<int>(e, f);
	cout << "e= " << e << endl;
	cout << "f= " << f << endl;
}

int main()
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}