#include<iostream>
using namespace std;

//���ࣺ
//��̬��̬���������ء����������
//��̬��̬�������ࡢ�麯��
//
//����
//��̬��̬������ַ��󶨣�����׶�ȷ��������ַ
//��̬��̬������ַ��󶨣����н׶�ȷ��������ַ

class Animal
{
public:
	virtual void speak() //ʹ���麯������ַ���
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};

//��ַ��󶨣�����׶ξ�ȷ��������ַ��animal�������speak����������Animal���еĺ���
void doSpeak(Animal& animal)
{
	animal.speak();
}

void test1()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//��̬��̬������
//1. �м̳й�ϵ
//2. ������д������麯��
//��̬��̬ʹ�ã�
//�����ָ�롢����ָ���������