#include<iostream>
using namespace std;

int* func()
{
	int a = 10; //创建一个局部变量
	return &a; //返回局部变量的地址
}

int main()
{
	int* p = func(); //接收func函数的返回值
	cout << *p << endl; //解引用输出（编译器做一次保留）
	cout << *p << endl; //再次输出（不再保留，无法输出10）

	system("pause");
	return 0;
}
//除局部变量外，形参数据也会放在栈区

/*栈区
* 由编译器自动分配和释放，存放函数的参数值、局部变量
* 注意：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
*/