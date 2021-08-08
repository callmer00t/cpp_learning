#include<iostream>
using namespace std;
#include<vector>

//vector容量和大小

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

	//判断是否为空
	if (v1.empty()) //true表示容器为空
	{
		cout << "v1 为空" << endl;
	}
	else
	{
		cout << "v1 非空" << endl;
		cout << "v1 的容量为：" << v1.capacity() << endl; //容量
		cout << "v1 的大小为：" << v1.size() << endl; //大小
	}

	//重新指定大小
	v1.resize(15, 100); //如果重新指定大小比原来的大，默认用0填充，可以通过第二个参数指定填充值
	printVector(v1);

	v1.resize(5); //如果重新指定大小比原来的小，超出部分会被删掉
	printVector(v1);
}


int main()
{
	test1();

	system("pause");
	return 0;
}