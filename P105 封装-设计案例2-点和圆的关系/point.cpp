#include "point.h" //�Զ����ͷ�ļ�ʹ��˫���Ű���

//����������ʵ��
//����X
void Point::setX(int x) //������ǰ��������������������߱������ú�����ָ����ĳ�Ա����
{
	m_X = x;
}
//��ȡX
int Point::getX()
{
	return m_X;
}
//����Y
void Point::setY(int y)
{
	m_Y = y;
}
//��ȡY
int Point::getY()
{
	return m_Y;
}