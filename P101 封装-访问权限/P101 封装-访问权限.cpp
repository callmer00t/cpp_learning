#include<iostream>
using namespace std;

class Person
{
public:
	string m_Name; //����

protected:
	string m_Car; //����

private:
	int m_Password; //����

public:
	void func()
	{
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}
};

int main()
{
	Person p1;
	p1.m_Name = "����";
	//p1.m_Car = "����"; //protected ���ⲻ�ɷ���
	//p1.m_Password = 654321; //private ���ⲻ�ɷ���

	system("pause");
	return 0;
}

//Public:		��Ա���ڿ��Է��ʣ�������Է���
//Protected:	��Ա���ڿ��Է��ʣ����ⲻ���Է��ʣ���������Է��ʸ���ı�������
//Private:	��Ա���ڿ��Է��ʣ����ⲻ���Է��ʣ������಻���Է��ʸ����˽������