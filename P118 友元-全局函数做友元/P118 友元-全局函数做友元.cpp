#include<iostream>
#include<string>
using namespace std;

//ȫ�ֺ�������Ԫ

class Building //������
{
	friend void goodGay(Building* building); //goodGay������Building�����Ԫ�����Է������е�˽�г�Ա
public:
	string m_SittingRoom; //��������������
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}
private:
	string m_BedRoom; //���ң�˽������
};

//ȫ�ֺ���
void goodGay(Building *building)
{
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ������ڷ��ʣ�" << building->m_BedRoom << endl;
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