#include<iostream>
#include<fstream> //����ͷ�ļ�
using namespace std;

//�������ļ�-д�ļ�

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test1()
{
	//1. ����ͷ�ļ�
	//2. ����������
	ofstream ofs; //Ҳ����ֱ��д ofstream ofs("person.txt",ios::out | ios::binary)
	//3. ���ļ�
	ofs.open("person.txt", ios::out | ios::binary); //ʹ�ö����Ʒ�ʽд�ļ�
	//4. д�ļ�
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(Person));
	//5. �ر��ļ�
	ofs.close();
}

int main()
{
	test1();

	system("pause");
	return 0;
}