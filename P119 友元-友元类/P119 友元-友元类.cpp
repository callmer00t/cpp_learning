#include<iostream>
#include<string>
using namespace std;

//类做友元

class Building
{
	friend class GoodGay; //GoodGay类是Building类的友元，可以访问本类中的私有成员
public:
	Building(); //构造函数
	string m_SittingRoom; //客厅
private:
	string m_BedRoom; //卧室
};

class GoodGay
{
public:
	GoodGay(); //构造函数
	void visit(); //访问Building中的属性
	Building* building;

};

//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	//创建房间对象
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}

void test1()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test1();

	system("pause");
	return 0;
}