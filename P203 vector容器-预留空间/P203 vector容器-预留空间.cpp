#include<iostream>
using namespace std;
#include<vector>

//预留空间作用：减少vector在动态扩展容量时的扩展次数
void test1()
{
	vector<int>v;

	//使用reserve预留空间
	v.reserve(100000);

	int num = 0; //统计开辟空间的次数
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num = " << num << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
