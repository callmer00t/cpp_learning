#include<iostream>
using namespace std;

void showValue(const int& val)
{
	//int a = 1000; //ʹ����const����ֹ�ⲿ�޸Ĳ���ֵ
	cout << "val=" << val << endl;
}

int main()
{
/*	int a = 10;
	const int& ref = 10;*/ //���const�󣬱�����ת��Ϊ int temp = 10; const int& ref = temp;
	/*���ֱ��д int& ref = 10; �ǲ��Ϸ��ģ���Ϊ10��һ���������ڳ����������ñ����Ƕ�������ջ��������*/

	int a = 100;
	showValue(a);

	system("pause");
	return 0;
}

/*
ʹ�ó����������βΣ���ֹ������ı��β�
*/