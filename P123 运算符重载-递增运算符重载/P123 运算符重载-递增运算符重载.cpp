#include<iostream>
using namespace std;

//�Զ������ͱ���
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ��++�����
	MyInteger& operator++() //����ֵ��m_Num��������MyInteger
	{
		m_Num++;
		return *this; //����������*this
		//ǰ��++����++���㣬�ٽ�������
		//����MyInteger���ö�����ֵ����Ϊ�������ֵ���޷�ʵ���ۼӣ�++(++a)������һ�ε����󣬷�����һ���µĶ��󣬵ڶ��ε����Ƕ��µĶ����������������������Ƕ�ͬһ����������������
	}

	//���غ���++�����
	MyInteger operator++(int) //������ֵ���Ͳ�ͬ���������غ�������Ҫ������ͬ���У�int��Ϊռλ��������������ǰ������õ���
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;
		//����++��1.��¼��ǰֵ��2.��++���㣬3.����¼��ֵ����
		//���õ����ķ���������ֵ�����������ã���Ϊtemp�Ǿֲ����󣬺���ִ�к��ͷţ��ٴ����ü�Ϊ�Ƿ�����
	}
private:
	int m_Num;
};

//����<<�����
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}



void test1()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test2()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}