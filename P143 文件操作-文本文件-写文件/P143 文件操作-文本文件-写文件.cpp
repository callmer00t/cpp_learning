#include<iostream>
#include<fstream> //�ļ�����ͷ�ļ�
using namespace std;

void test1()
{
	//1. ����ͷ�ļ�
	//2. ����������
	ofstream ofs;
	//3. ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);
	//4. д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//5. �ر��ļ�
	ofs.close();
}

int main()
{
	test1();

	system("pause");
	return 0;
}