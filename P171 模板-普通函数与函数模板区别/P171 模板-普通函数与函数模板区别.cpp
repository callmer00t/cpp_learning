#include<iostream>
using namespace std;

//普通函数
int myAdd1(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myAdd2(T a, T b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd1(a, b) << endl;
	cout << myAdd1(a, c) << endl; //char型c隐式转换为int型，与a相加

	//自动类型推导
	cout << myAdd2(a, b) << endl; //正确，ab可以通过自动类型推导转换为int型
	//cout << myAdd2(a, c) << endl; //错误，a是int型，c是char型，模板中的T不能确定应该是何种类型

	//显式指定类型
	cout << myAdd2<int>(a, c) << endl; //正确，显式指定为int类型，c会被隐式类型转换为int型
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//结论：
//普通函数调用时可发生自动类型转换（隐式类型转换）
//函数模板调用时，如果使用自动类型推导，不会发生隐式类型转换
//如果使用显式指定类型，可以发生隐式类型转换