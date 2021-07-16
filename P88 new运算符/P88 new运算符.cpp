#include<iostream>
using namespace std;

int* func()
{
	//在堆区创建整型数据
	//new返回该数据类型的指针
	int* p = new int(10);
	return p;
}

void test1() //new的基本语法
{
	//堆区数据由程序员管理
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	delete p;
	//前三次输出正常，delete后输出异常
	//cout << *p << endl; //内存已被释放，再次访问是非法操作
}

void test2() //在堆区利用new开辟数组
{
	//创建10个整型数据的数组
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100; //给10个元素赋值，100~109
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放堆区的数组
	delete[] arr; //释放数组使用中括号

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}