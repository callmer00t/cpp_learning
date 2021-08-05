#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;
	//类模板中的成员函数
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	//func1和func2两个成员函数在调用前不会被创建，因为此时无法确定obj的数据类型
};

void test1()
{
	MyClass<Person1>m; 
	m.func1(); //func1可以调用，因为指定了Person1的类型
	//m.func2(); //func2不可以调用，因为指定的是Person1的类型
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//结论：
//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时创建