#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "�޲ι��캯������" << endl;
	}
	Person(int age, int height)
	{
		m_age = age;
		m_height = new int(height); //����
		cout << "�вι��캯������" << endl;
	}
	Person(const Person& p)
	{
		cout << "�������캯������" << endl;
		m_age = p.m_age;
		//m_height = p.m_height; ������Ĭ��ʵ��

		//���
		m_height = new int(*p.m_height);
	}
	~Person()
	{
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "������������" << endl;
	}
	int m_age;
	int* m_height;
};

void test1()
{
	Person p1(18, 160);
	cout << "p1������Ϊ��" << p1.m_age << endl;
	cout << "p1�����Ϊ��" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << endl;
	cout << "p2�����Ϊ��" << *p2.m_height << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}

//ǳ�������������⣺�����ڴ��ظ��ͷ�
//ʹ�������������Լ�ʵ�ֿ������캯��