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
		} //��Ӵ˶Σ���ߴ��뽡׳�ԣ�����ǿ�ָ�룬��ֱ��return����ִ������Ĵ���
		cout << "age=" << m_Age << endl; //����Ĭ��Ϊ this->m_Age
	}
	int m_Age;
};

void test1()
{
	Person* p = NULL; 
	p->showClassName();
	p->showPersonAge(); //��Ϊ�ǿ�ָ�룬���Բ��ܷ���showPersonAge�е�m_Age����

}

int main()
{
	test1();

	system("pause");
	return 0;
}