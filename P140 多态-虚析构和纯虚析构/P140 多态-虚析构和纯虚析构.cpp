#include<iostream>
#include<string>
using namespace std;

//��̬ʹ���ǣ�����ָ�롢����ָ��������󣬸���ָ���޷�ʹ�������е��������������������޷��ͷ�
//�����ʽ���������е�����������Ϊ��������������
//�������ʹ��������Ĺ��ԣ�
//ʹ����ָ������ͷ��������
//��Ҫ����ĺ���ʵ��
//�������ʹ�������������
//�����������������ڳ����࣬�޷�ʵ��������
//�������﷨��virtual ~����() {}

class Animal
{
public:
	Animal()
	{
		cout << "Animal ���캯������" << endl;
	}
	//virtual ~Animal() //����ʹ�����������������ָ���޷��ͷ�������������
	//{
	//	cout << "Animal ������������" << endl;
	//}
	virtual ~Animal() = 0; //��������
	virtual void speak() = 0; 
};

Animal::~Animal()
{
	cout << "Animal ����������������" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat ���캯������" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name << "Сè��˵��" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat ������������" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;
};

void test1()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	delete animal;
}

int main()
{
	test1();

	system("pause");
	return 0;
}