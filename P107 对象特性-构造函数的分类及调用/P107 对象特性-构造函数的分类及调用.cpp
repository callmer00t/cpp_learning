#include<iostream>
using namespace std;

//按参数分：有参构造、无参构造
//按类型分：普通构造、拷贝构造
//调用方式：括号法、显示法、隐式转换法

class Person
{
public:
	Person()
	{
		cout << "Person 无参构造函数的调用" << endl;
	}

	Person(int a)
	{
		age = a;
		cout << "Person 有参构造函数的调用" << endl;
	}

	Person(const Person &p)
	{
		age = p.age;
		cout << "Person 拷贝构造函数的调用" << endl;
	}

	~Person()
	{
		cout << "Person 析构函数的调用" << endl;
	}

	int age;
};

void test1()
{
	//括号法
	Person p; //默认构造函数调用
	Person p2(10); //有参构造函数调用
	Person p3(p2); //拷贝构造函数调用
	cout << "p2 的年龄为：" << p2.age << endl;
	cout << "p3 的年龄为：" << p3.age << endl;
	//注意事项1：
	//	调用默认构造函数时不要加()
	//	因为编译器会认为在做函数声明

	//显示法
	Person p4 = Person(10); //有参构造函数调用
	Person p5 = Person(p2); //拷贝构造函数调用

	Person(10); //匿名对象，当前行执行结束后，系统会立即回收匿名对象
	cout << "test" << endl;
	//注意事项2：
	//	不要利用拷贝构造函数初始化匿名对象
	//	因为编译器会认为在做对象声明

	//隐式转换法
	Person p6 = 10; //有参构造函数调用，等价于 Person p6 = Person(10);
	Person p7 = p6; //拷贝构造函数调用
}

int main()
{
	test1();

	system("pause");
	return 0;
}