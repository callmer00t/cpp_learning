#include<iostream>
using namespace std;

//ϵ����Ƶ��ȱʧ�˲��֣������ۿ� https://www.bilibili.com/video/BV1bz4y1S7gs

//��̬��Ա����

class Person
{
public:
	//1. ���ж�����ͬһ������
	//2. �ڱ���׶η����ڴ�
	//3. ���������������ʼ��
	static int m_A;

	//��̬��Ա����Ҳ���з���Ȩ��
private:
	static int m_B; //˽�������������޷�����
};

int Person::m_A = 100;
int Person::m_B = 200;

void test1()
{
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test2()
{
	//��̬��Ա����������ĳ���������ж�������˾�̬��Ա���������ַ��ʷ�ʽ
	//1. ͨ���������
	Person p;
	cout << p.m_A << endl;
	//2. ͨ����������
	cout << Person::m_A << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}