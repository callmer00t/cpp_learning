#include<iostream>
using namespace std;
#include<string>

//案例描述：实现一个通用的数组类，要求如下：
//可以对内置数据类型以及自定义数据类型的数据进行存储
//将数组中的数据存储到堆区
//构造函数中可以传入数组的容量
//提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//提供尾插法和尾删法对数组中的数据进行增加和删除
//可以通过下表的方式访问数组中的元素
//可以获取数组中当前元素个数和数组的容量

#include "myArray.hpp"

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test1()
{
	//MyArray <int>arr1(5);
	//MyArray<int>arr2(arr1);
	//MyArray<int>arr3(100);
	//arr3 = arr1;
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1 的输出为：" << endl;
	printIntArray(arr1);
	cout << "arr1 的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1 的大小为：" << arr1.getSize() << endl;
	MyArray<int>arr2(arr1);
	cout << "arr2 的输出为：" << endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2 的容量为：" << arr2.getCapacity() << endl;
	cout << "arr2 的大小为：" << arr2.getSize() << endl;
}

//测试自定义数据类型
class Person
{
public:
	Person()
	{

	};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << "\t年龄：" << arr[i].m_Age << endl;
	}
}

void test2()
{
	MyArray<Person>arr(10);
	Person p1("孙悟空", 999);
	Person p2("韩信", 20);
	Person p3("妲己", 19);
	Person p4("赵云", 30);
	Person p5("安其拉", 27);
	//将数据插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//打印数组
	printPersonArray(arr);
	//输出容量
	cout << "arr 的容量为：" << arr.getCapacity() << endl;
	//输出大小
	cout << "arr 的大小为：" << arr.getSize() << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}