#include<iostream>
using namespace std;

void showValue(const int& val)
{
	//int a = 1000; //使用了const，防止外部修改参数值
	cout << "val=" << val << endl;
}

int main()
{
/*	int a = 10;
	const int& ref = 10;*/ //添加const后，编译器转换为 int temp = 10; const int& ref = temp;
	/*如果直接写 int& ref = 10; 是不合法的，因为10是一个常量，在常量区，引用必须是堆区或者栈区的数据*/

	int a = 100;
	showValue(a);

	system("pause");
	return 0;
}

/*
使用场景：修饰形参，防止误操作改变形参
*/