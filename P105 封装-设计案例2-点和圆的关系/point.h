#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

//������࣬��д��Ա�����������������������ʵ��
class Point
{
private:
	int m_X;
	int m_Y;
public:
	//����X
	void setX(int x);
	//��ȡX
	int getX();
	//����Y
	void setY(int y);
	//��ȡY
	int getY();
};