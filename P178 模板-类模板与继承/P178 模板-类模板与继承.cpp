#include<iostream>
using namespace std;

template<class T>
class Base
{
	T m;
};
//基类是一个类模板

//class Son :public Base //错误，不能按普通继承方式直接写父类名，因为如果不指定T的类型，编译器无法知道要对子类分配多少内存空间
class Son1 :public Base<int> //使用<>指定类型
{

};
//这样做只能指定父类中的一个类型，如果需要灵活指定父类T类型，子类也需要变为类模板

template<class T1, class T2>
class Son2 :public Base<T2> //将子类Son2变为类模板
{
public:
	Son2()
	{
		cout << "T1 的类型为：" << typeid(T1).name() << endl;
		cout << "T2 的类型为：" << typeid(T2).name() << endl;
	} //构造函数，输出T1、T2类型
	T1 obj;
};

void test1()
{
	//Son1 s1; //可以通过子类实例化对象
}

void test2()
{
	Son2<int, char>s2; //类模板实例化对象必须显式指定类型
	//数据类型int->T1->obj
	//数据类型char->T2->Base
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}

//类模板遇到继承，需要注意：
//当子类继承的父类是一个模板时，子类在声明的时候，要指出父类中T的类型
//如果不指定，编译器无法对子类分配内存
//如果想灵活制定出父类中T的类型，子类也需要变为类模板
