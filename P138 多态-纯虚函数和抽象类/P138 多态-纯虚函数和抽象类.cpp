#include<iostream>
using namespace std;

class Base
{
public:
	//����ֻҪ�д��麯�������Ϊ�����࣬�޷�ʵ�����������������д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0; //���麯�����﷨��virtual���麯���������=0

};

class Son :public Base
{
public:
	virtual void func()
	{

	};
};

void test1()
{
	//Base b; //�������޷�ʵ��������
	//new Base; //�������޷�ʵ��������
	Son s; //���������д�����еĴ��麯���������޷�ʵ��������
}

int main()
{


	system("pause");
	return 0;
}