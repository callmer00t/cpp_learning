#include<iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) //����Ĭ��ֵ
{
	return a + b + c;
}

int main()
{
	cout << func(10, 30) << endl; //���ָ����ֵ����ʹ��Ĭ��ֵ�����δ��ֵ��ʹ��Ĭ��ֵ

	system("pause");
	return 0;
}

//�﷨������ֵ���� ������(�β� = Ĭ��ֵ) {}
//ע�����
//1. ���ĳ��λ���Ѿ���Ĭ�ϲ������Ӹ�λ����󣬴����ң���������Ĭ��ֵ
//2. ����������ʵ��ֻ����һ����Ĭ�ϲ���
//int func2(int a = 10, int b = 10); //��������
//
//int func2(int a, int b)
//{
//	return a + b;
//}
////����ʵ��
