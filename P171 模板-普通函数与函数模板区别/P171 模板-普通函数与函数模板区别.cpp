#include<iostream>
using namespace std;

//��ͨ����
int myAdd1(int a, int b)
{
	return a + b;
}

//����ģ��
template<class T>
T myAdd2(T a, T b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd1(a, b) << endl;
	cout << myAdd1(a, c) << endl; //char��c��ʽת��Ϊint�ͣ���a���

	//�Զ������Ƶ�
	cout << myAdd2(a, b) << endl; //��ȷ��ab����ͨ���Զ������Ƶ�ת��Ϊint��
	//cout << myAdd2(a, c) << endl; //����a��int�ͣ�c��char�ͣ�ģ���е�T����ȷ��Ӧ���Ǻ�������

	//��ʽָ������
	cout << myAdd2<int>(a, c) << endl; //��ȷ����ʽָ��Ϊint���ͣ�c�ᱻ��ʽ����ת��Ϊint��
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//���ۣ�
//��ͨ��������ʱ�ɷ����Զ�����ת������ʽ����ת����
//����ģ�����ʱ�����ʹ���Զ������Ƶ������ᷢ����ʽ����ת��
//���ʹ����ʽָ�����ͣ����Է�����ʽ����ת��