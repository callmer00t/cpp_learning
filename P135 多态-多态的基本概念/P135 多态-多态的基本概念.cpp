#include<iostream>
using namespace std;

//分类：
//静态多态：函数重载、运算符重载
//动态多态：派生类、虚函数
//
//区别：
//静态多态函数地址早绑定：编译阶段确定函数地址
//动态多态函数地址晚绑定：运行阶段确定函数地址

class Animal
{
public:
	virtual void speak() //使用虚函数，地址晚绑定
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//地址早绑定，编译阶段就确定函数地址，animal对象调用speak函数，会走Animal类中的函数
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

//动态多态条件：
//1. 有继承关系
//2. 子类重写父类的虚函数
//动态多态使用：
//父类的指针、引用指向子类对象