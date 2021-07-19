#include<iostream>
using namespace std;

class Cube
{
private:
	//立方体类的属性，长宽高，设置为私有
	int m_L;
	int m_W;
	int m_H;
public:
	//设置长
	void setL(int L)
	{
		m_L = L;
	}
	//获取长
	int getL()
	{
		return m_L;
	}
	//设置宽
	void setW(int W)
	{
		m_W = W;
	}
	//获取宽
	int getW()
	{
		return m_W;
	}
	//设置高
	void setH(int H)
	{
		m_H = H;
	}
	//获取高
	int getH()
	{
		return m_H;
	}
	//计算立方体面积
	int caculateS()
	{
		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
	}
	//计算立方体体积
	int caculateV()
	{
		return m_L * m_W * m_H;
	}
	//使用成员函数比较两个立方体是否相等
	bool isSameByClass(Cube &c) //成员函数仅需传递1个参数
	{
		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}
};

//使用全局函数比较两个立方体是否相等
bool isSame(Cube &c1, Cube &c2) //全局函数需要传递2个参数
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout << "c1的面积为：" << c1.caculateS() << endl;
	cout << "c1的体积为：" << c1.caculateV() << endl;

	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//使用全局函数判断
	bool ret1 = isSame(c1, c2);
	if (ret1)
	{
		cout << "全局函数判断：c1和c2是相同的" << endl;
	}
	else
	{
		cout << "全局函数判断：c1和c2是不同的" << endl;
	}

	//使用成员函数判断
	bool ret2 = c1.isSameByClass(c2);
	if (ret2)
	{
		cout << "成员函数判断：c1和c2是相同的" << endl;
	}
	else
	{
		cout << "成员函数判断：c1和c2是不同的" << endl;
	}

	system("pause");
	return 0;
}