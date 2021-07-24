#include<iostream>
using namespace std;

//自定义整型变量
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符
	MyInteger& operator++() //返回值是m_Num，类型是MyInteger
	{
		m_Num++;
		return *this; //返回自身，用*this
		//前置++，先++运算，再将自身返回
		//返回MyInteger引用而不是值是因为如果返回值，无法实现累加（++(++a)），做一次递增后，返回是一个新的对象，第二次递增是对新的对象做递增，返回引用则是对同一个对象做连续递增
	}

	//重载后置++运算符
	MyInteger operator++(int) //仅返回值类型不同，不能重载函数，需要参数不同才行，int作为占位参数，用于区分前置与后置递增
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;
		//后置++，1.记录当前值，2.做++运算，3.将记录的值返回
		//后置递增的返回类型是值，而不是引用，因为temp是局部对象，函数执行后被释放，再次引用即为非法操作
	}
private:
	int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}



void test1()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test2()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}