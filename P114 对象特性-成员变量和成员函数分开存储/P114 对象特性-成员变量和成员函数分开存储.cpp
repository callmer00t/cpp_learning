#include<iostream>
using namespace std;

//��Ա�����ͳ�Ա�����ֿ��洢
class Person
{
	int m_A; //�Ǿ�̬��Ա������������Ķ���
	static int m_B; //��̬��Ա��������������Ķ���
	void func()
	{

	} //�Ǿ�̬��Ա��������������Ķ���
	static void func2()
	{

	} //��̬��Ա��������������Ķ���
};
int Person::m_B = 0;

void test1()
{
	Person p; //�ն���ռ���ڴ�ռ�Ϊ��1
	cout << "size of p=" << sizeof(p) << endl;
}

void test2()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}