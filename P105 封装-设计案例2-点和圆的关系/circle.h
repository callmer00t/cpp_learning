#pragma once
#include<iostream>
#include "point.h"
using namespace std;

//����Բ��
class Circle
{
private:
	int m_R; //�뾶
	Point m_Center; //Բ��
public:
	//����Բ��
	void setCenter(Point center);
	//��ȡԲ��
	Point getCenter();
	//���ð뾶
	void setR(int r);
	//��ȡ�뾶
	int getR();
};