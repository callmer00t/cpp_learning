#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "Person �вι��캯������" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "Person �������캯������" << endl;
	}
	~Person()
	{
		cout << "Person ������������" << endl;
	}
	int m_Age;
};

//ʹ��һ���Ѵ�����ϵĶ����ʼ��һ���¶���
void test1()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2 ������Ϊ��" << p2.m_Age << endl;
}

//��ֵ���ݵķ�ʽ������������ֵ
void doWork1(Person p) //�β�p
{

}
void test2()
{
	Person p;
	doWork1(p); //ʵ��p
}

//��ֵ�ķ�ʽ���ؾֲ�����
Person doWork2()
{
	Person p3;
	cout << (int*)&p3 << endl; //p3�ĵ�ַ
	return p3; //p3��һ���ֲ�����returnʱ���´��һ���µĶ���������ݵ�������
}
void test3()
{
	Person p = doWork2();
	cout << (int*)&p << endl; //p�ĵ�ַ����p3��ͬ
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}