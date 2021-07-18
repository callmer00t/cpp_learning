#include<iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) //设置默认值
{
	return a + b + c;
}

int main()
{
	cout << func(10, 30) << endl; //如果指定了值，不使用默认值，如果未传值，使用默认值

	system("pause");
	return 0;
}

//语法：返回值类型 函数名(形参 = 默认值) {}
//注意事项：
//1. 如果某个位置已经有默认参数，从该位置向后，从左到右，都必须有默认值
//2. 函数声明和实现只能有一个有默认参数
//int func2(int a = 10, int b = 10); //函数声明
//
//int func2(int a, int b)
//{
//	return a + b;
//}
////函数实现
