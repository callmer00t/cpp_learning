#include<iostream>
using namespace std;
#include<string>

//�ַ������Һ��滻

//����
void test1()
{
	string str1 = "abcdefg";
	int pos = str1.find("de");
	if (pos == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	pos = str1.rfind("fg");
	cout << "pos = " << pos << endl; //rfind���������
}//������0��ʼ���Ҳ�������-1

//�滻
void test2()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111"); //��һ�������ǴӼ���������ʼ�滻���ڶ����������滻����λ���������������滻Ϊʲô�ַ�
	cout << "str1 = " << str1 << endl;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}