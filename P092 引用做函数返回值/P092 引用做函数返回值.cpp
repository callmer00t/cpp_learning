#include<iostream>
using namespace std;

int& test1()
{
	int a = 10; //�ֲ������������ջ��
	return a;
}

int& test2()
{
	static int a = 10; //��̬�����������ȫ����
	return a;
}

int main()
{
	int& ref1 = test1();
	cout << "ref1=" << ref1<< endl; //��һ�η�����ȷ��ֵ����Ϊ���������˱���
	cout << "ref1=" << ref1 << endl; //�ڶ��η������ֵ����Ϊ�ڴ��Ѿ����ͷ�

	int& ref2 = test2();
	cout << "ref2=" << ref2 << endl; //��һ�η�����ȷ��ֵ

	test2() = 1000; //����������Ϊ��ֵ
	cout << "ref2=" << ref2 << endl; //�ڶ��η�����ȷ��ֵ

	system("pause");
	return 0;
}

/*
ע������
1. ��Ҫ���ؾֲ�����������
2. �����ĵ��ÿ�����Ϊ��ֵ
*/