#include<iostream>
using namespace std;

//定义全局变量
int g_a = 10;
int g_b = 10;

//定义const修饰的全局变量（全局常量）
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
	//定义局部变量
	int a = 10;
	int b = 10;

	//输出局部变量地址
	cout << "局部变量a的地址为：" << (int)&a << endl;
	cout << "局部变量b的地址为：" << (int)&b << endl;

	//输出局部变量地址
	cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
	cout << "全局变量g_b的地址为：" << (int)&g_b << endl;

	//定义静态变量
	static int s_a = 10;
	static int s_b = 10;

	//输出静态变量地址
	cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
	cout << "静态变量s_b的地址为：" << (int)&s_b << endl;

	//输出字符串常量地址
	cout << "字符串常量的地址为：" << (int)&"Hello World" << endl;

	//定义const修饰的局部变量（局部常量）
	const int c_l_a = 10;
	const int c_l_b = 10;

	//输出全局常量地址
	cout << "全局常量s_a的地址为：" << (int)&c_g_a << endl;
	cout << "全局常量s_b的地址为：" << (int)&c_g_b << endl;

	//输出局部常量地址
	cout << "局部常量s_a的地址为：" << (int)&c_l_a << endl;
	cout << "局部常量s_b的地址为：" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}

/*结论
局部区存放：局部变量、局部常量
全局区存放：全局变量、静态变量、字符串常量、全局常量
*/