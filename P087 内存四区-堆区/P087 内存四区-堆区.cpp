#include<iostream>
using namespace std;

int* func()
{
	int * p = new int(10); //使用new关键字开辟内存，new返回的是指针
	return p; //返回内存地址
}

int main()
{
	int *p = func(); //调用函数
	cout << *p << endl; //解引用输出数据值
	cout << *p << endl; //再次输出
}

/*堆区
* 程序员分配和释放，程序结束时由操作系统回收
* 使用 new 关键字在堆区开辟内存
*/