#include<iostream>
using namespace std;

class c1
{
	int m_A; //Ĭ��Ȩ��private
};

struct s1
{
	int m_A; //Ĭ��Ȩ��public
};

int main()
{
	c1 c1;
	//c1.m_A = 100; //�������ⲻ�������
	s1 s1;
	s1.m_A = 100; //������Է���

	system("pause");
	return 0;
}

//struct Ĭ�Ϸ���Ȩ��Ϊ public
//class Ĭ�Ϸ���Ȩ��Ϊ private