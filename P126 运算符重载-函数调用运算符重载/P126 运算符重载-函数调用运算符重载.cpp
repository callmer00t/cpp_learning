#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
	//���غ������������()
	void operator()(string str)
	{
		cout << str << endl;
	}
};

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void MyPrint2(string str)
{
	cout << str << endl;
}

void test1()
{
	MyPrint myprint;
	myprint("Hello world"); //������������أ�Hello world���ݸ�str
	MyPrint2("Hello world"); //���Ǻ�������
}

void test2()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret=" << ret << endl;

	//������������
	cout << MyAdd()(100, 100) << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}