#include<iostream>
using namespace std;
#include<vector>

//vector�����ʹ�С

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//�ж��Ƿ�Ϊ��
	if (v1.empty()) //true��ʾ����Ϊ��
	{
		cout << "v1 Ϊ��" << endl;
	}
	else
	{
		cout << "v1 �ǿ�" << endl;
		cout << "v1 ������Ϊ��" << v1.capacity() << endl; //����
		cout << "v1 �Ĵ�СΪ��" << v1.size() << endl; //��С
	}

	//����ָ����С
	v1.resize(15, 100); //�������ָ����С��ԭ���Ĵ�Ĭ����0��䣬����ͨ���ڶ�������ָ�����ֵ
	printVector(v1);

	v1.resize(5); //�������ָ����С��ԭ����С���������ֻᱻɾ��
	printVector(v1);
}


int main()
{
	test1();

	system("pause");
	return 0;
}