#include<iostream>
using namespace std;
#include<string>

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "������" << this->m_Name << "���䣺" << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

//1. ָ����������
void printPerson1(Person<string, int>& p) //ָ���������ͣ���p������ֱ�����ȥ�������õķ�ʽ���ݣ��˴�Person<string, int>& p��Ϊ����printPerson1()���β�
{
	p.showPerson(); //����showPerson()����
}

//2. ����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p) //�������е�����string, intģ�廯ΪT1, T2
{
	p.showPerson();
	cout << "T1 ������Ϊ��" << typeid(T1).name() << endl; //��ʾģ���е�T�Զ��Ƶ�������������
	cout << "T2 ������Ϊ��" << typeid(T2).name() << endl;
}

//3. ������ģ�廯
template<class T>
void printPerson3(T &p) //������Person��ģ�廯ΪT���������Զ��Ƶ�
{
	p.showPerson();
	cout << "T ������Ϊ��" << typeid(T).name() << endl;
}

void test1()
{
	Person<string, int>p("�����", 100);
	printPerson1(p); //ʵ��p���ݸ�printPerson1()����
}

void test2()
{
	Person<string, int>p("��˽�", 99);
	printPerson2(p);
}

void test3()
{
	Person<string, int>p("��ɮ", 30);
	printPerson3(p);
}

int main()
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}

//��ģ��ʵ�����������������εķ�ʽ


