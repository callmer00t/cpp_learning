#include<iostream>
using namespace std;

//c++��������һ�������4������
//1. Ĭ�Ϲ��캯��
//2. Ĭ����������
//3. Ĭ�Ͽ������캯���������Խ���ֵ����
//4. ��ֵ����� operator=�������Խ���ֵ����

class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	int* m_Age;
	~Person() //�������������ֶ��ͷŶ�������
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//���ظ�ֵ�����
	Person& operator=(Person& p)
	{
		//���ж��Ƿ��������ڶ���������У����ͷ�
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//���
		m_Age = new int(*p.m_Age);
		//��������
		return *this;
	}
};

void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3 = p2 = p1; //��ֵ���㣬ǳ���������������������������ᵼ���ڴ��ظ��ͷţ�������������������ʹ�����
	cout << "p1 ������Ϊ��" << *p1.m_Age << endl;
	cout << "p2 ������Ϊ��" << *p2.m_Age << endl;
	cout << "p3 ������Ϊ��" << *p2.m_Age << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}