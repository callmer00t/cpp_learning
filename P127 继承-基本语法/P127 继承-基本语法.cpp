#include<iostream>
using namespace std;

//����ҳ��
class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ�����������ײ���" << endl;
	}
	void left()
	{
		cout << "Java��Python��C++���������������б�" << endl;
	}
};

//Javaҳ��
class Java:public BasePage
{
public:
	void content()
	{
		cout << "Java ѧ����Ƶ" << endl;
	}
};

//Pythonҳ��
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python ѧ����Ƶ" << endl;
	}
};

//CPPҳ��
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++ ѧ����Ƶ" << endl;
	}
};

void test1()
{

	cout << "Java ��Ƶҳ�����£�" << endl;
	cout << "-------------------------------------------------" << endl;
	Java ja;
	ja.header();
	ja.content();
	ja.footer();
	cout << "-------------------------------------------------" << endl;

	cout << "Python ��Ƶҳ�����£�" << endl;
	cout << "-------------------------------------------------" << endl;
	Python py;
	py.header();
	py.content();
	py.footer();
	cout << "-------------------------------------------------" << endl;

	cout << "C++ ��Ƶҳ�����£�" << endl;
	cout << "-------------------------------------------------" << endl;
	CPP cpp;
	cpp.header();
	cpp.content();
	cpp.footer();
	cout << "-------------------------------------------------" << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//�̳��﷨��class ���ࣨ�����ࣩ:�̳з�ʽ ���ࣨ���ࣩ