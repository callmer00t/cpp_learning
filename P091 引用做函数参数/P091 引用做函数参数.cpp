#include<iostream>
using namespace std;

//��������
//1. ֵ����
void Swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "�β�a=" << a << endl;
	cout << "�β�b=" << b << endl;
	//�βν���
}

//2. ��ַ����
void Swap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3. ���ô���
void Swap3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{

	int a = 10;
	int b = 20;

	//1. ֵ����
	Swap1(a, b);
	cout << "ֵ����ʵ��a=" << a << endl;
	cout << "ֵ����ʵ��b=" << b << endl;
	//ʵ��δ�ı�

	//2. ��ַ����
	//Swap2(&a, &b);
	//cout << "��ַ����ʵ��a=" << a << endl;
	//cout << "��ַ����ʵ��b=" << b << endl;
	//ʵ���Ѹı�

	//3. ���ô���
	Swap3(a, b);
	cout << "���ô���ʵ��a=" << a << endl;
	cout << "���ô���ʵ��b=" << b << endl;
	//ʵ���Ѹı�

	system("pause");
	return 0;
}

/*
���ݲ������ַ�ʽ��ֵ���ݣ���ַ����
ֵ���ݣ��ββ����޸�ʵ��
�����������ü�����ʹ�β��޸�ʵ��
����ʹ��ָ�룬Ҳ��ʵ���β��޸�ʵ��
*/