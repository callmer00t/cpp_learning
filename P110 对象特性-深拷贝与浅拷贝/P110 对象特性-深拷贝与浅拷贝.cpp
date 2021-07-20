#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "无参构造函数调用" << endl;
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height); //堆区
		cout << "有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		cout << "拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//m_height = p.m_height; 编译器默认实现

		//深拷贝
		m_height = new int(*p.m_height);
	}
	~Person()
	{
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "析构函数调用" << endl;
	}
	int m_age;
	int* m_height;
};

void test1()
{
	Person p1(18, 160);
	cout << "p1的年龄为：" << p1.m_age << endl;
	cout << "p1的身高为：" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << endl;
	cout << "p2的身高为：" << *p2.m_height << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}

//浅拷贝带来的问题：堆区内存重复释放
//使用深拷贝解决，即自己实现拷贝构造函数