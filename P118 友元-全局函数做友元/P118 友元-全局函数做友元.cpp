#include<iostream>
#include<string>
using namespace std;

//全局函数做友元

class Building //房屋类
{
	friend void goodGay(Building* building); //goodGay函数是Building类的友元，可以访问类中的私有成员
public:
	string m_SittingRoom; //客厅，公共属性
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
private:
	string m_BedRoom; //卧室，私有属性
};

//全局函数
void goodGay(Building *building)
{
	cout << "好基友全局函数正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友全局函数正在访问：" << building->m_BedRoom << endl;
}

void test1()
{
	Building building;
	goodGay(&building);
}

int main()
{
	test1();

	system("pause");
	return 0;
}