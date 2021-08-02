#include<iostream>
using namespace std;

template<class T> //typename 可以替换为 class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1. 自动类型推导必须推出一致的数据类型 T 才可以使用
void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b);
	//mySwap(a, c); //错误，因为自动类型推导a是int，c是char，但形参都是T类型，不一致
}

//2. 模板必须要确定出 T 的数据类型才可以使用
template<class T>
void func()
{
	cout << "func 的调用" << endl;
}

void test2()
{
	//func(); //错误，因为没有用到模板中的 T 数据类型
	func<int>(); //正确，
}

int main()
{
	test2();

	system("pause");
	return 0;
}