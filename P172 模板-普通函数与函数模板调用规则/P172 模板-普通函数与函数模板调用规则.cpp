#include<iostream>
using namespace std;

void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "调用的模板" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) //参数个数不同，发生重载
{
	cout << "调用重载的模板" << endl;
}

void test1()
{
	int a = 10;
	int b = 20;
	myPrint(a, b); //函数模板和普通函数都可以实现，优先调用普通函数

	myPrint<>(a, b); //通过空模板参数列表调用函数模板

	myPrint(a, b, 100); //函数模板可以发生重载

	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //调用模板，因为编译器认为隐式类型转换不如自动推导为T型简单，模板产生更好的匹配
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//调用规则：
//1. 如果函数模板和普通函数都可以实现，优先调用普通函数
//2. 可以通过空模板参数列表来强制调用函数模板
//3. 函数模板也可以发生重载
//4. 如果函数模板可以产生更好的匹配，优先调用函数模板