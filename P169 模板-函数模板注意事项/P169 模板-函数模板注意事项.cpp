#include<iostream>
using namespace std;

template<class T> //typename �����滻Ϊ class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1. �Զ������Ƶ������Ƴ�һ�µ��������� T �ſ���ʹ��
void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b);
	//mySwap(a, c); //������Ϊ�Զ������Ƶ�a��int��c��char�����βζ���T���ͣ���һ��
}

//2. ģ�����Ҫȷ���� T ���������Ͳſ���ʹ��
template<class T>
void func()
{
	cout << "func �ĵ���" << endl;
}

void test2()
{
	//func(); //������Ϊû���õ�ģ���е� T ��������
	func<int>(); //��ȷ��
}

int main()
{
	test2();

	system("pause");
	return 0;
}