#include<iostream>
using namespace std;

void func()
{
	cout << "func() �ĵ���" << endl;
}

void func(int a) //��������������ͬ
{
	cout << "func(int a) �ĵ���" << endl;
}

void func(double a) //�������Ͳ�ͬ
{
	cout << "func(double a) �ĵ���" << endl;
}

void func(double a, int b) //��������˳��ͬ
{
	cout << "func(double a, int b) �ĵ���" << endl;
}

void func(int a, double b) //��������˳��ͬ
{
	cout << "func(int a, double b) �ĵ���" << endl;
}

//������Ϊ��������
void func2(int& a)
{
	cout << "func2(int& a) �ĵ���" << endl;
}

void func2(const int& a) //����������ͨ�����ǲ�ͬ��������
{
	cout << "func2(const int& a) �ĵ���" << endl;
}

//������������Ĭ�ϲ���
void func3(int a, int b = 10)
{
	cout << "func3(int a, int b) �ĵ���" << endl;
}

void func3(int a)
{
	cout << "func3(int a) �ĵ���" << endl;
}

int main()
{
	func(); //���� func ����
	func(10); //���� func(int a) ����
	func(3.14); //���� func(double a) ����
	func(3.14, 10); //���� func(double a, int b) ����
	func(10, 3.14); //���� func(int a, double b) ����

	//������Ϊ��������
	int a = 10;
	func2(a); //a�Ǳ�����������ͨ���ú���

	func2(10); //10�ǳ��������ó����ú���

	//������������Ĭ�ϲ���
	//func3(10); //���ֶ����ԣ����ڵ�һ��func3��b��������Ĭ��ֵ��Ҳ���Ե���

	system("pause");
	return 0;
}


//���ã�������������ͬ����߸�����
//������
//	1. ͬһ����������
//	2. ����������ͬ
//	3. �������� ���Ͳ�ͬ �� ������ͬ �� ˳��ͬ
//ע�⣺�����ķ���ֵ��������Ϊ�������ص�����

//ע�����
//	1. ������Ϊ��������
//	2. ����������������Ĭ�ϲ���