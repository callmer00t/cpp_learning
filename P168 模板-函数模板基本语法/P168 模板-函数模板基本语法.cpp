#include<iostream>
using namespace std;

//ģ���﷨��
//template<typename T>
//������������

//�������ͽ�������
template<typename T> //����һ��ģ�壬����T��һ��ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//�Զ������Ƶ�
void test1()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

void test2()
{
	double c = 1.1;
	double d = 2.2;
	mySwap(c, d);
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;
}

//��ʽָ������
void test3()
{
	int e = 10;
	int f = 20;
	mySwap<int>(e, f);
	cout << "e= " << e << endl;
	cout << "f= " << f << endl;
}

int main()
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}