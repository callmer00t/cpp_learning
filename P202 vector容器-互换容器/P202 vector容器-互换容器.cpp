#include<iostream>
using namespace std;
#include<vector>

//vector容器互换

//1. 基本使用
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	cout << "交换后：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//2. 实际用途
//巧用swap可以收缩内存空间
void test2()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v 的容量为：" << v.capacity() << endl;
	cout << "v 的大小为：" << v.size() << endl;

	v.resize(3); //重新指定大小
	cout << "v 的容量为：" << v.capacity() << endl; //容量不变
	cout << "v 的大小为：" << v.size() << endl; //大小变为3

	vector<int>(v).swap(v);
	cout << "v 的容量为：" << v.capacity() << endl; //容量为3
	cout << "v 的大小为：" << v.size() << endl; //大小为3

	//vector<int>(v) 是匿名对象（为便于区分，称为x），会按照v当前大小（3）初始化对象
	//swap()是交换函数，将容量大的v与容量小的x交换
	//交换后v指向的是原x的空间，容量为3
}



int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}