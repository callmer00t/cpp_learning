#include<iostream>
using namespace std;
#include<string>

//�Ӵ�

void test1()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3); //��һ�������Ǵ�X������ʼ��ȡ�ִ����ڶ��������ǽ�ȡYλ�ַ�
	cout << "subStr = " << subStr << endl;
}

//ʵ�ð���
void test2()
{
	//�������ַ�л�ȡ�û�����Ϣ
	string email = "zhangsan@abc.com";
	int pos = email.find('@');
	string username = email.substr(0, pos);
	cout << "username = " << username << endl;
}


int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}