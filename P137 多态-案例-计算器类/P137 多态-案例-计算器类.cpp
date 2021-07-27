#include<iostream>
#include<string>
using namespace std;

//�ֱ�ʹ����ͨд���Ͷ�̬����ʵ�ּ�������

//��ͨд��
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}
	int m_Num1;
	int m_Num2;
};

void test1()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

//ʹ�ö�̬����ʵ��
//����������
class AbstractCaculator
{
public:
	virtual int getResult() //��̬���������������麯����������д
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

//�ӷ���������
class AddCaculator :public AbstractCaculator
{
public:
	int getResult() //��д�����е��麯��
	{
		return m_Num1 + m_Num2;
	}
};

//������������
class SubCaculator :public AbstractCaculator
{
public:
	int getResult() //��д�����е��麯��
	{
		return m_Num1 - m_Num2;
	}
};

//�˷���������
class MulCaculator:public AbstractCaculator
{
public:
	int getResult() //��д�����е��麯��
	{
		return m_Num1 * m_Num2;
	}
};

void test2()
{
	//��̬ʹ������������ָ�롢����ָ���������

	AbstractCaculator* abc = new AddCaculator; //�ӷ�
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->m_Num1 + abc->m_Num2 << endl;
	delete abc; //�ֶ����ٶ�������

	abc = new SubCaculator; //����
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->m_Num1 - abc->m_Num2 << endl;

	abc = new MulCaculator; //�˷�
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->m_Num1 * abc->m_Num2 << endl;
}


int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}