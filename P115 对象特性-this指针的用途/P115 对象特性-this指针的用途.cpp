#include<iostream>
using namespace std;

//thisָ����;��

//1. ������Ƴ�ͻ
class Person
{
public:
	Person(int age)
	{
		this->age = age; //�������this����������Ϊ Person ���캯���ڵ�����age��ͬһ���������·��ĳ�Ա����age��ͬ�����Ե���ʱδ�ܽ�18������Ա����age
	}
	int age;

	Person& PersonAddAge(Person &p) //������صĲ������ã�����ֵ��������Ϊ20����Ϊ����ÿ������캯������һ���µĶ������
	{
		this->age += p.age;
		return *this;
		//thisָ��p2��ָ�룬*thisָ��p2������
	}
};
//���õĽ���취��ʹ�����õı���淶����Ա����ʹ�õ��������ƣ�����m_Age


void test1()
{
	Person p1(18);
	cout << "p1 ������Ϊ��" << p1.age << endl;
}

//2. ���ض�����
void test2()
{
	Person p1(10);
	Person p2(10);

	//��ʽ���˼��
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2 ������Ϊ��" << p2.age << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}