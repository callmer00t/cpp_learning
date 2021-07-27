#include<iostream>
#include<string>
using namespace std;

//分别使用普通写法和多态技术实现计算器类

//普通写法
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

//使用多态技术实现
//计算器基类
class AbstractCaculator
{
public:
	virtual int getResult() //多态条件：父类中有虚函数，子类重写
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

//加法计算器类
class AddCaculator :public AbstractCaculator
{
public:
	int getResult() //重写父类中的虚函数
	{
		return m_Num1 + m_Num2;
	}
};

//减法计算器类
class SubCaculator :public AbstractCaculator
{
public:
	int getResult() //重写父类中的虚函数
	{
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class MulCaculator:public AbstractCaculator
{
public:
	int getResult() //重写父类中的虚函数
	{
		return m_Num1 * m_Num2;
	}
};

void test2()
{
	//多态使用条件：父类指针、引用指向子类对象

	AbstractCaculator* abc = new AddCaculator; //加法
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->m_Num1 + abc->m_Num2 << endl;
	delete abc; //手动销毁堆区数据

	abc = new SubCaculator; //减法
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->m_Num1 - abc->m_Num2 << endl;

	abc = new MulCaculator; //乘法
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