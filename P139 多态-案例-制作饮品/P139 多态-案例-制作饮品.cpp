#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSth() = 0;
	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSth();
	}
};

//制作咖啡
class Coffee :public AbstractDrinking
{
	virtual void Boil()
	{
		cout << "煮纯净水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入咖啡杯" << endl;
	}
	//加入辅料
	virtual void PutSth()
	{
		cout << "加入牛奶" << endl;
	}
};

//制作茶水
class Tea :public AbstractDrinking
{
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入茶杯" << endl;
	}
	//加入辅料
	virtual void PutSth()
	{
		cout << "加入枸杞" << endl;
	}
};

void doWork(AbstractDrinking * drk)
{
	drk->makeDrink();
	delete drk;
}

void test1()
{
	//制作咖啡
	doWork(new Coffee);
	cout << "--------------------" << endl;
	//制作茶水
	doWork(new Tea);
}

int main()
{
	test1();

	system("pause");
	return 0;
}