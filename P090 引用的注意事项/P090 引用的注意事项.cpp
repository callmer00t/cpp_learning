#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;

	int c = 20;
	b = c; //赋值操作，不是更改引用

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	//&b = c; //引用不能更改

	system("pause");
	return 0;
}

/*
1. 引用必须要初始化
2. 引用一旦初始化，就不可以更改
*/