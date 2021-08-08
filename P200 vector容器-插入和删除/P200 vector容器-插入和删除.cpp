#include<iostream>
using namespace std;
#include<vector>

//vector插入和删除

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
	
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	//遍历
	printVector(v1);

	//尾删
	v1.pop_back();
	printVector(v1);

	//插入
	v1.insert(v1.begin(), 100); //第一个参数是迭代器
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000); //n个elem的方式插入
	printVector(v1);

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	v1.erase(v1.begin(), v1.end()); //区间的方式删除
	printVector(v1); //空容器，仅输出一个换行符

	v1.clear(); //等同于v1.erase(v1.begin(), v1.end());
	printVector(v1);
}


int main()
{
	test1();

	system("pause");
	return 0;
}