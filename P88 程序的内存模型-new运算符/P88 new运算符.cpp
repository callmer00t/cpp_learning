#include<iostream>
using namespace std;

int* func()
{
	//�ڶ���������������
	//new���ظ��������͵�ָ��
	int* p = new int(10);
	return p;
}

void test1() //new�Ļ����﷨
{
	//���������ɳ���Ա����
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	delete p;
	//ǰ�������������delete������쳣
	//cout << *p << endl; //�ڴ��ѱ��ͷţ��ٴη����ǷǷ�����
}

void test2() //�ڶ�������new��������
{
	//����10���������ݵ�����
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100; //��10��Ԫ�ظ�ֵ��100~109
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//�ͷŶ���������
	delete[] arr; //�ͷ�����ʹ��������

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}