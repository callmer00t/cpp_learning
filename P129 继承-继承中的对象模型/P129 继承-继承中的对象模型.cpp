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

//int����ռ4�ֽڣ����������зǾ�̬��Ա������ʲô���ԣ����ᱻ����̳�����
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