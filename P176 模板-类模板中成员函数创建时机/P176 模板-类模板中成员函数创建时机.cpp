#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;
	//��ģ���еĳ�Ա����
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	//func1��func2������Ա�����ڵ���ǰ���ᱻ��������Ϊ��ʱ�޷�ȷ��obj����������
};

void test1()
{
	MyClass<Person1>m; 
	m.func1(); //func1���Ե��ã���Ϊָ����Person1������
	//m.func2(); //func2�����Ե��ã���Ϊָ������Person1������
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//���ۣ�
//��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//��ģ���еĳ�Ա�����ڵ���ʱ����