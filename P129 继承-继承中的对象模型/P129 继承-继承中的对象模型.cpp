#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};

//int类型占4字节，父类中所有非静态成员（无论什么属性）都会被子类继承下来
void test1()
{
	cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}