#include<iostream>
using namespace std;

void func(int a, int) //��������ֻ��д�������ͣ���ռλ����
{
	cout << "this is func" << endl;
}

void func2(int a, int = 10) //ռλ����������Ĭ��ֵ
{
	cout << "this is func2" << endl;
}

int main()
{
	func(10, 10);//��������ʱ������д����������ռλ����ָ�����͵�ʵ��

	system("pause");
	return 0;
}