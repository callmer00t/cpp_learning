#include<iostream>
using namespace std;

#include<string>

template<class T1, class T2>
class Person;
//��ǰ�ñ�����֪��Person�࣬������һ����ģ��

//ȫ�ֺ�������ʵ��
template<class T1, class T2> //��Ҫ���ģ��
void printPerson2(Person<T1, T2> p) //ȫ�ֺ����������������
{
	cout << "����ʵ��" << endl;
	cout << "������" << p.m_Name << endl;
	cout << "���䣺" << p.m_Age << endl;
}
//���Ǻ���ģ�������ʵ��
//��ǰ�ñ�����֪��printPerson2����

template<class T1,class T2>
class Person
{
	//ȫ�ֺ�������ʵ��
	friend void printPerson1(Person<T1, T2> p) //��ȫ�ֺ�������Ϊ��Ԫ��ʹ����Է������ڵ�˽�г�Ա
	{
		cout << "������" << p.m_Name << endl;
		cout << "���䣺" << p.m_Age << endl;
	}
	//friend void printPerson2(Person<T1, T2> p); //����ʵ�֣����ڽ�д����
	//����������ͨ��������������
	friend void printPerson2<>(Person<T1, T2> p);
	//�ӿ�ģ������б���ʾ���Ǻ���ģ�����������

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

void test1()
{
	Person<string, int>p("Tom", 20);
	printPerson1(p);
}

void test2()
{
	Person<string, int>p("Jerry", 30);
	printPerson2(p);
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}