#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int& b = a;

	int c = 20;
	b = c; //��ֵ���������Ǹ�������

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	//&b = c; //���ò��ܸ���

	system("pause");
	return 0;
}

/*
1. ���ñ���Ҫ��ʼ��
2. ����һ����ʼ�����Ͳ����Ը���
*/