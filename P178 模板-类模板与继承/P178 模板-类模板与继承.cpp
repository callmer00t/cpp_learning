#include<iostream>
using namespace std;

template<class T>
class Base
{
	T m;
};
//������һ����ģ��

//class Son :public Base //���󣬲��ܰ���ͨ�̳з�ʽֱ��д����������Ϊ�����ָ��T�����ͣ��������޷�֪��Ҫ�������������ڴ�ռ�
class Son1 :public Base<int> //ʹ��<>ָ������
{

};
//������ֻ��ָ�������е�һ�����ͣ������Ҫ���ָ������T���ͣ�����Ҳ��Ҫ��Ϊ��ģ��

template<class T1, class T2>
class Son2 :public Base<T2> //������Son2��Ϊ��ģ��
{
public:
	Son2()
	{
		cout << "T1 ������Ϊ��" << typeid(T1).name() << endl;
		cout << "T2 ������Ϊ��" << typeid(T2).name() << endl;
	} //���캯�������T1��T2����
	T1 obj;
};

void test1()
{
	//Son1 s1; //����ͨ������ʵ��������
}

void test2()
{
	Son2<int, char>s2; //��ģ��ʵ�������������ʽָ������
	//��������int->T1->obj
	//��������char->T2->Base
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}

//��ģ�������̳У���Ҫע�⣺
//������̳еĸ�����һ��ģ��ʱ��������������ʱ��Ҫָ��������T������
//�����ָ�����������޷�����������ڴ�
//���������ƶ���������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��
