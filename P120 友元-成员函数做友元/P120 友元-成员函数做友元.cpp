#include<iostream>
#include<string>
using namespace std;

//��Ա��������Ԫ

class Building; //�������

class GoodGay
{
public:
	GoodGay();
	void visit(); //visit�������Է���Building�е�˽�г�Ա
	void visit2(); //viist2���������Է���Building�е�˽�г�Ա
	Building* building;
};

class Building
{
	friend void GoodGay::visit(); //GoodGay�������µ�visit������Building�����Ԫ�����Է������е�˽�г�Ա
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//����ʵ�ֳ�Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit �������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit �������ڷ��ʣ�" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit �������ڷ��ʣ�" << building->m_SittingRoom << endl;
	//cout << "visit �������ڷ��ʣ�" << building->m_BedRoom << endl;
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