#include<iostream>
using namespace std;

//c++编译器给一个类添加4个函数
//1. 默认构造函数
//2. 默认析构函数
//3. 默认拷贝构造函数，对属性进行值拷贝
//4. 赋值运算符 operator=，对属性进行值拷贝

class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	int* m_Age;
	~Person() //利用析构函数手动释放堆区数据
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//重载赋值运算符
	Person& operator=(Person& p)
	{
		//先判断是否有属性在堆区，如果有，先释放
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//深拷贝
		m_Age = new int(*p.m_Age);
		//返回自身
		return *this;
	}
};

void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1; //赋值运算，浅拷贝，如果有上面的析构函数，会导致内存重复释放，程序崩溃。解决方案：使用深拷贝
	cout << "p1 的年龄为：" << *p1.m_Age << endl;
	cout << "p2 的年龄为：" << *p2.m_Age << endl;
	cout << "p3 的年龄为：" << *p2.m_Age << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}