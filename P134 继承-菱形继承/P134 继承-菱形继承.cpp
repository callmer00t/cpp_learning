#include<iostream>
using namespace std;

//�������������̳�ͬһ�����࣬����ĳ����ͬʱ�̳�������������

class Animal
{
public:
	int m_Age;
};

class Sheep :virtual public Animal //ʹ����̳н�����μ̳������ظ�����
{

};

class Camel :virtual public Animal 
{

};


class Alpaca :public Sheep, public Camel
{

};

void test1()
{
	Alpaca a;
	a.Sheep::m_Age = 18;
	a.Camel::m_Age = 28;
	//�����μ̳�����������ӵ����ͬ���ݣ���Ҫʹ���������������
	cout << "a.Sheep::m_Age = " << a.Sheep::m_Age << endl;
	cout << "a.Camel::m_Age = " << a.Camel::m_Age << endl;
	cout << "a.m_Age = " << a.m_Age << endl; //ʹ����̳�Ҳ����ʹ�����ַ�ʽ����������������

	//���μ̳е��������ظ�����Դ�˷�
}

int main()
{
	test1();

	system("pause");
	return 0;
}