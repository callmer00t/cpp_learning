#include<iostream>
using namespace std;

class Person
{
private:
	string m_Name; //���� �ɶ�д
	int m_Age; //���� �ɶ�д����Χ0-150
	string m_Lover; //���� ֻд

public:
	void setName(string name)
	{
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "��������" << endl;
			return;
		}
		m_Age = age;
	}
	int getAge()
	{
		//m_Age = 0; //��ʼ������
		return m_Age;
	}
	void setLover(string lover)
	{
		m_Lover = lover;
	}
};

int main()
{
	Person p;
	p.setName("����");
	cout << "������" << p.getName() << endl;
	p.setLover("�Ծ�");
	p.setAge(20);
	cout << "���䣺" << p.getAge() << endl;

	system("pause");
	return 0;
}

//��Ա��������Ϊ˽�У��ŵ㣺
//1. �Լ����ƶ�дȨ��
//2. д����ʱ���ڼ��������Ч��