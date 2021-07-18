#include<iostream>
using namespace std;

void func(int a, int) //函数参数只填写数据类型，即占位参数
{
	cout << "this is func" << endl;
}

void func2(int a, int = 10) //占位参数可以有默认值
{
	cout << "this is func2" << endl;
}

int main()
{
	func(10, 10);//函数调用时必须填写函数定义中占位参数指定类型的实参

	system("pause");
	return 0;
}