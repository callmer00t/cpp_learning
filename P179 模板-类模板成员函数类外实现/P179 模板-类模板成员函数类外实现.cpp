#include<iostream>
using namespace std;
#include<string>

//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	void showPerson()
//	{
//		cout << "������" << this->m_Name << endl;
//		cout << "���䣺" << this->m_Age << endl;
//	}
//	T1 m_Name;
//	T2 m_Age;
//};
////����ʵ��

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age); //���ڽ�д����������ʵ��
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}
	void showPerson(); //���ڽ�д����������ʵ��
	//{
	//	cout << "������" << this->m_Name << endl;
	//	cout << "���䣺" << this->m_Age << endl;
	//}
	T1 m_Name;
	T2 m_Age;
};

//���캯��������ʵ��
template<class T1,class T2> //���template��֪������T1��T2��������
Person<T1, T2>::Person(T1 name, T2 age) //���������Person�����<T1, T2>��ʾ����ģ���Ա����������ʵ�֣��������<T1, T2>������ͨ��Ա����������ʵ��
{
	this->m_Name = name;
	this->m_Age = age;
}

//��Ա����������ʵ��
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "������" << this->m_Name << endl;
	cout << "���䣺" << this->m_Age << endl;
}

void test1()
{
	Person<string, int>p("Tom", 20);
	p.showPerson();
}


int main()
{
	test1();

	system("pause");
	return 0;
}