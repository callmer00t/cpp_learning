#include<iostream>
using namespace std;

//�������֣��вι��졢�޲ι���
//�����ͷ֣���ͨ���졢��������
//���÷�ʽ�����ŷ�����ʾ������ʽת����

class Person
{
public:
	Person()
	{
		cout << "Person �޲ι��캯���ĵ���" << endl;
	}

	Person(int a)
	{
		age = a;
		cout << "Person �вι��캯���ĵ���" << endl;
	}

	Person(const Person &p)
	{
		age = p.age;
		cout << "Person �������캯���ĵ���" << endl;
	}

	~Person()
	{
		cout << "Person ���������ĵ���" << endl;
	}

	int age;
};

void test1()
{
	//���ŷ�
	Person p; //Ĭ�Ϲ��캯������
	Person p2(10); //�вι��캯������
	Person p3(p2); //�������캯������
	cout << "p2 ������Ϊ��" << p2.age << endl;
	cout << "p3 ������Ϊ��" << p3.age << endl;
	//ע������1��
	//	����Ĭ�Ϲ��캯��ʱ��Ҫ��()
	//	��Ϊ����������Ϊ������������

	//��ʾ��
	Person p4 = Person(10); //�вι��캯������
	Person p5 = Person(p2); //�������캯������

	Person(10); //�������󣬵�ǰ��ִ�н�����ϵͳ������������������
	cout << "test" << endl;
	//ע������2��
	//	��Ҫ���ÿ������캯����ʼ����������
	//	��Ϊ����������Ϊ������������

	//��ʽת����
	Person p6 = 10; //�вι��캯�����ã��ȼ��� Person p6 = Person(10);
	Person p7 = p6; //�������캯������
}

int main()
{
	test1();

	system("pause");
	return 0;
}