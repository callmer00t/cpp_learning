//���ļ���д

#include<iostream>
#include<math.h>
using namespace std;

//���ļ���д�������Ӧ��ͷ�ļ�
#include "circle.h"
#include "point.h"

////�������
//class Point
//{
//private:
//	int m_X;
//	int m_Y;
//public:
//	//����X
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//��ȡX
//	int getX()
//	{
//		return m_X;
//	}
//	//����Y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//��ȡY
//	int getY()
//	{
//		return m_Y;
//	}
//};

////����Բ��
//class Circle
//{
//private:
//	int m_R; //�뾶
//	Point m_Center; //Բ��
//public:
//	//����Բ��
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//��ȡԲ��
//	Point getCenter()
//	{
//		return m_Center;
//	}
//	//���ð뾶
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//��ȡ�뾶
//	int getR()
//	{
//		return m_R;
//	}
//
//};

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle& c, Point& p)
{
	//��������֮������ƽ��
	int distance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
	//����뾶��ƽ��
	int rDistance = pow((c.getR()), 2);
	//�жϹ�ϵ
	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{
	//����һ��Բ
	Circle c1;
	c1.setR(10);
	Point center1;
	center1.setX(10);
	center1.setY(0);
	c1.setCenter(center1);

	//����һ����
	Point p1;
	p1.setX(10);
	p1.setY(10);

	//�жϹ�ϵ
	isInCircle(c1, p1);

	system("pause");
	return 0;
}

//���ļ���д����ͷ�ļ���Դ�ļ�