#include<iostream>
using namespace std;

class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		} //添加此段，提高代码健壮性，如果是空指针，则直接return，不执行下面的代码
		cout << "age=" << m_Age << endl; //属性默认为 this->m_Age
	}
	int m_Age;
};

void test1()
{
	Person* p = NULL; 
	p->showClassName();
	p->showPersonAge(); //因为是空指针，所以不能访问showPersonAge中的m_Age属性

}

int main()
{
	test1();

	system("pause");
	return 0;
}