#include<iostream>
using namespace std;

void myPrint(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "���õ�ģ��" << endl;
}

template<typename T>
void myPrint(T a, T b, T c) //����������ͬ����������
{
	cout << "�������ص�ģ��" << endl;
}

void test1()
{
	int a = 10;
	int b = 20;
	myPrint(a, b); //����ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����

	myPrint<>(a, b); //ͨ����ģ������б���ú���ģ��

	myPrint(a, b, 100); //����ģ����Է�������

	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //����ģ�壬��Ϊ��������Ϊ��ʽ����ת�������Զ��Ƶ�ΪT�ͼ򵥣�ģ��������õ�ƥ��
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//���ù���
//1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3. ����ģ��Ҳ���Է�������
//4. �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��