#include<iostream>
using namespace std;

//#include<string>
//
//template<class T1, class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "������" << this->m_Name << endl;
//	cout << "���䣺" << this->m_Age << endl;
//}

//#include"Person.cpp" //�������1��ֱ�Ӱ���cpp�ļ�
#include"Person.hpp" //�������2������hpp�ļ�

void test1()
{
	Person<string, int>p("Jerry", 18);
	p.showPerson();
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//���⣺��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
//�����
//1. ֱ�Ӱ���.cppԴ�ļ�
//2. ��������ʵ��д��ͬһ���ļ��У���׺��Ϊ.hpp