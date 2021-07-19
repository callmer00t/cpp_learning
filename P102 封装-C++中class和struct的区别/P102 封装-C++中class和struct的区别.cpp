#include<iostream>
using namespace std;

class c1
{
	int m_A; //默认权限private
};

struct s1
{
	int m_A; //默认权限public
};

int main()
{
	c1 c1;
	//c1.m_A = 100; //报错，类外不允许访问
	s1 s1;
	s1.m_A = 100; //类外可以访问

	system("pause");
	return 0;
}

//struct 默认访问权限为 public
//class 默认访问权限为 private