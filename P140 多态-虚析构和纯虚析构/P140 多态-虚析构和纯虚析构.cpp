#include<iostream>
#include<string>
using namespace std;

//多态使用是：父类指针、引用指向子类对象，父类指针无法使用子类中的析构函数，堆区数据无法释放
//解决方式：将父类中的析构函数改为虚析构或纯虚析构
//虚析构和纯虚析构的共性：
//使父类指针可以释放子类对象
//需要具体的函数实现
//虚析构和纯虚析构的区别：
//纯虚析构，该类属于抽象类，无法实例化对象
//虚析构语法：virtual ~类名() {}

class Animal
{
public:
	Animal()
	{
		cout << "Animal 构造函数调用" << endl;
	}
	//virtual ~Animal() //父类使用虚析构，解决父类指针无法释放子类对象的问题
	//{
	//	cout << "Animal 析构函数调用" << endl;
	//}
	virtual ~Animal() = 0; //纯虚析构
	virtual void speak() = 0; 
};

Animal::~Animal()
{
	cout << "Animal 纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat 构造函数调用" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "Cat 析构函数调用" << endl;
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