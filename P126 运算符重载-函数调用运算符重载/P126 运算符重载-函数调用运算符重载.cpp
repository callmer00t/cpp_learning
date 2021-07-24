#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
	//重载函数调用运算符()
	void operator()(string str)
	{
		cout << str << endl;
	}
};

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void MyPrint2(string str)
{
	cout << str << endl;
}

void test1()
{
	MyPrint myprint;
	myprint("Hello world"); //这是运算符重载，Hello world传递给str
	MyPrint2("Hello world"); //这是函数调用
}

void test2()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret=" << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}