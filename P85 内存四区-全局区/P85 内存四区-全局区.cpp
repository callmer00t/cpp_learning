#include<iostream>
using namespace std;

//����ȫ�ֱ���
int g_a = 10;
int g_b = 10;

//����const���ε�ȫ�ֱ�����ȫ�ֳ�����
const int c_g_a = 10;
const int c_g_b = 10;

int main()
{
	//����ֲ�����
	int a = 10;
	int b = 10;

	//����ֲ�������ַ
	cout << "�ֲ�����a�ĵ�ַΪ��" << (int)&a << endl;
	cout << "�ֲ�����b�ĵ�ַΪ��" << (int)&b << endl;

	//����ֲ�������ַ
	cout << "ȫ�ֱ���g_a�ĵ�ַΪ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַΪ��" << (int)&g_b << endl;

	//���徲̬����
	static int s_a = 10;
	static int s_b = 10;

	//�����̬������ַ
	cout << "��̬����s_a�ĵ�ַΪ��" << (int)&s_a << endl;
	cout << "��̬����s_b�ĵ�ַΪ��" << (int)&s_b << endl;

	//����ַ���������ַ
	cout << "�ַ��������ĵ�ַΪ��" << (int)&"Hello World" << endl;

	//����const���εľֲ��������ֲ�������
	const int c_l_a = 10;
	const int c_l_b = 10;

	//���ȫ�ֳ�����ַ
	cout << "ȫ�ֳ���s_a�ĵ�ַΪ��" << (int)&c_g_a << endl;
	cout << "ȫ�ֳ���s_b�ĵ�ַΪ��" << (int)&c_g_b << endl;

	//����ֲ�������ַ
	cout << "�ֲ�����s_a�ĵ�ַΪ��" << (int)&c_l_a << endl;
	cout << "�ֲ�����s_b�ĵ�ַΪ��" << (int)&c_l_b << endl;

	system("pause");
	return 0;
}

/*����
�ֲ�����ţ��ֲ��������ֲ�����
ȫ������ţ�ȫ�ֱ�������̬�������ַ���������ȫ�ֳ���
*/