#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;

//定义点类，仅写成员函数的声明，无需包括函数实现
class Point
{
private:
	int m_X;
	int m_Y;
public:
	//设置X
	void setX(int x);
	//获取X
	int getX();
	//设置Y
	void setY(int y);
	//获取Y
	int getY();
};