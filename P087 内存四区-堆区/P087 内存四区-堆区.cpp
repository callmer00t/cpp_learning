#include<iostream>
using namespace std;

int* func()
{
	int * p = new int(10); //ʹ��new�ؼ��ֿ����ڴ棬new���ص���ָ��
	return p; //�����ڴ��ַ
}

int main()
{
	int *p = func(); //���ú���
	cout << *p << endl; //�������������ֵ
	cout << *p << endl; //�ٴ����
}

/*����
* ����Ա������ͷţ��������ʱ�ɲ���ϵͳ����
* ʹ�� new �ؼ����ڶ��������ڴ�
*/