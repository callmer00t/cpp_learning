#include<iostream>
#include<string>
using namespace std;

//成员函数做友元

class Building; //类的声明

class GoodGay
{
public:
	GoodGay();
	void visit(); //visit函数可以访问Building中的私有成员
	void visit2(); //viist2函数不可以访问Building中的私有成员
	Building* building;
};

class Building
{
	friend void GoodGay::visit(); //GoodGay作用域下的visit函数是Building类的友元，可以访问其中的私有成员
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit 函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit 函数正在访问：" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit 函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit 函数正在访问：" << building->m_BedRoom << endl;
}

void test1()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test1();

	system("pause");
	return 0;
}