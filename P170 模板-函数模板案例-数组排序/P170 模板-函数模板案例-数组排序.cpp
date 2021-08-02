#include<iostream>
using namespace std;

//实现通用的对数组进行排序的函数
//排序规则：从大到小
//算法：选择排序
//测试：char int

//交换函数模板
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//数组排序函数模板
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //认定最大值下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j]) //如果认定的最大值max比下一个（j下标）的值小，则交换
			{
				max = j;
			}
		}
		if (max != i) //如果认定的最大值不等于下标为i的元素，则交换
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

//打印数组模板
template<class T>
void printArrar(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1()
{
	//测试char数组
	char charArr[] = "bdecfa";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArrar(charArr, num);
}

int main()
{
	test1();

	system("pause");
	return 0;
}