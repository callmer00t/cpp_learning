#include<iostream>
using namespace std;
#include<string>

//�ַ������ɾ��

void test1()
{
	string str = "hello";
	str.insert(1, "111"); //��һ�������Ǵ�X������λ�ò��룬�ڶ��������ǲ��������
	cout << "str = " << str << endl;

	str.erase(1, 3); //��һ�������Ǵ�X����λ�ÿ�ʼɾ�����ڶ���������ɾ��X���ַ�
	cout << "str = " << str << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}