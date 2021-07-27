#include<iostream>
using namespace std;

//概念：两个派生类继承同一个基类，又有某个类同时继承这两个派生类

class Animal
{
public:
	int m_Age;
};

class Sheep :virtual public Animal //使用虚继承解决菱形继承数据重复问题
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
	//当菱形继承中两个父类拥有相同数据，需要使用作用域进行区分
	cout << "a.Sheep::m_Age = " << a.Sheep::m_Age << endl;
	cout << "a.Camel::m_Age = " << a.Camel::m_Age << endl;
	cout << "a.m_Age = " << a.m_Age << endl; //使用虚继承也可以使用这种方式，不会引发二义性

	//菱形继承导致数据重复，资源浪费
}

int main()
{
	test1();

	system("pause");
	return 0;
}