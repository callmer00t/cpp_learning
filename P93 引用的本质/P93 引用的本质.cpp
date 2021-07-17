#include<iostream>
using namespace std;

//发现是引用，转换为 int* const ref = &a;
void func(int& ref)
{
	ref = 100; //ref是引用，转换为 *ref = 100;
}

int main()
{
	int a = 10;
	
	//自动转换为 int* const ref = &a; 指针常量是指针指向不可更改，也说明了为什么引用不可更改
	int& ref = a;
	ref = 20; //内部发现ref是引用，自动转换为 *ref = 20;
	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;
	func(a);

	system("pause");
	return 0;
}

/*引用的本质：在C++内部实现使一个指针常量*/