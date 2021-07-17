#include<iostream>
using namespace std;

//交换函数
//1. 值传递
void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "形参a=" << a << endl;
	cout << "形参b=" << b << endl;
	//形参交换
}

//2. 地址传递
void Swap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3. 引用传递
void Swap3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{

	int a = 10;
	int b = 20;

	//1. 值传递
	Swap1(a, b);
	cout << "值传递实参a=" << a << endl;
	cout << "值传递实参b=" << b << endl;
	//实参未改变

	//2. 地址传递
	//Swap2(&a, &b);
	//cout << "地址传递实参a=" << a << endl;
	//cout << "地址传递实参b=" << b << endl;
	//实参已改变

	//3. 引用传递
	Swap3(a, b);
	cout << "引用传递实参a=" << a << endl;
	cout << "引用传递实参b=" << b << endl;
	//实参已改变

	system("pause");
	return 0;
}

/*
传递参数两种方式：值传递，地址传递
值传递：形参不能修改实参
可以利用引用技术，使形参修改实参
即不使用指针，也可实现形参修改实参
*/