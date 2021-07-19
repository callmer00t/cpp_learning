#include "point.h" //自定义的头文件使用双引号包含

//仅保留函数实现
//设置X
void Point::setX(int x) //函数名前添加作用域（类名），告诉编译器该函数是指定类的成员函数
{
	m_X = x;
}
//获取X
int Point::getX()
{
	return m_X;
}
//设置Y
void Point::setY(int y)
{
	m_Y = y;
}
//获取Y
int Point::getY()
{
	return m_Y;
}