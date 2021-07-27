#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSth() = 0;
	//������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSth();
	}
};

//��������
class Coffee :public AbstractDrinking
{
	virtual void Boil()
	{
		cout << "�󴿾�ˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뿧�ȱ�" << endl;
	}
	//���븨��
	virtual void PutSth()
	{
		cout << "����ţ��" << endl;
	}
};

//������ˮ
class Tea :public AbstractDrinking
{
	virtual void Boil()
	{
		cout << "���Ȫˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "����豭" << endl;
	}
	//���븨��
	virtual void PutSth()
	{
		cout << "�������" << endl;
	}
};

void doWork(AbstractDrinking * drk)
{
	drk->makeDrink();
	delete drk;
}

void test1()
{
	//��������
	doWork(new Coffee);
	cout << "--------------------" << endl;
	//������ˮ
	doWork(new Tea);
}

int main()
{
	test1();

	system("pause");
	return 0;
}