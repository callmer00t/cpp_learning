#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base ���캯��" << endl;
	}
	~Base()
	{
		cout << "Base ��������" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son ���캯��" << endl;
	}
	~Son()
	{
		cout << "Son ��������" << endl;
	}
};

void test1()
{
	//Base b;
	Son s;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//Base ���캯��
//Son ���캯��
//Son ��������
//Base ��������