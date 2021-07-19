//单文件编写

#include<iostream>
#include<math.h>
using namespace std;

//分文件编写需包含对应的头文件
#include "circle.h"
#include "point.h"

////定义点类
//class Point
//{
//private:
//	int m_X;
//	int m_Y;
//public:
//	//设置X
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//获取X
//	int getX()
//	{
//		return m_X;
//	}
//	//设置Y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//获取Y
//	int getY()
//	{
//		return m_Y;
//	}
//};

////定义圆类
//class Circle
//{
//private:
//	int m_R; //半径
//	Point m_Center; //圆心
//public:
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//
//};

//判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	//计算两点之间距离的平方
	int distance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
	//计算半径的平方
	int rDistance = pow((c.getR()), 2);
	//判断关系
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	//创建一个圆
	Circle c1;
	c1.setR(10);
	Point center1;
	center1.setX(10);
	center1.setY(0);
	c1.setCenter(center1);

	//创建一个点
	Point p1;
	p1.setX(10);
	p1.setY(10);

	//判断关系
	isInCircle(c1, p1);

	system("pause");
	return 0;
}

//分文件编写见各头文件和源文件