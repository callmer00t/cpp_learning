#include<iostream>
#include<string>
using namespace std;

//������Ԫ

class Building
{
	friend class GoodGay; //GoodGay����Building�����Ԫ�����Է��ʱ����е�˽�г�Ա
public:
	Building(); //���캯��
	string m_SittingRoom; //����
private:
	string m_BedRoom; //����
};

class GoodGay
{
public:
	GoodGay(); //���캯��
	void visit(); //����Building�е�����
	Building* building;

};

//����ʵ�ֳ�Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay()
{
	//�����������
	building = new Building;
}

void GoodGay::visit()
{
	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
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