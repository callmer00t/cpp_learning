#include<iostream>
using namespace std;

class Cube
{
private:
	//������������ԣ�����ߣ�����Ϊ˽��
	int m_L;
	int m_W;
	int m_H;
public:
	//���ó�
	void setL(int L)
	{
		m_L = L;
	}
	//��ȡ��
	int getL()
	{
		return m_L;
	}
	//���ÿ�
	void setW(int W)
	{
		m_W = W;
	}
	//��ȡ��
	int getW()
	{
		return m_W;
	}
	//���ø�
	void setH(int H)
	{
		m_H = H;
	}
	//��ȡ��
	int getH()
	{
		return m_H;
	}
	//�������������
	int caculateS()
	{
		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
	}
	//�������������
	int caculateV()
	{
		return m_L * m_W * m_H;
	}
	//ʹ�ó�Ա�����Ƚ������������Ƿ����
	bool isSameByClass(Cube &c) //��Ա�������贫��1������
	{
		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
		{
			return true;
		}
		return false;
	}
};

//ʹ��ȫ�ֺ����Ƚ������������Ƿ����
bool isSame(Cube &c1, Cube &c2) //ȫ�ֺ�����Ҫ����2������
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
	cout << "c1�����Ϊ��" << c1.caculateS() << endl;
	cout << "c1�����Ϊ��" << c1.caculateV() << endl;

	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//ʹ��ȫ�ֺ����ж�
	bool ret1 = isSame(c1, c2);
	if (ret1)
	{
		cout << "ȫ�ֺ����жϣ�c1��c2����ͬ��" << endl;
	}
	else
	{
		cout << "ȫ�ֺ����жϣ�c1��c2�ǲ�ͬ��" << endl;
	}

	//ʹ�ó�Ա�����ж�
	bool ret2 = c1.isSameByClass(c2);
	if (ret2)
	{
		cout << "��Ա�����жϣ�c1��c2����ͬ��" << endl;
	}
	else
	{
		cout << "��Ա�����жϣ�c1��c2�ǲ�ͬ��" << endl;
	}

	system("pause");
	return 0;
}