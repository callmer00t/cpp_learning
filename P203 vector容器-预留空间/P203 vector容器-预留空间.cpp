#include<iostream>
using namespace std;
#include<vector>

//Ԥ���ռ����ã�����vector�ڶ�̬��չ����ʱ����չ����
void test1()
{
	vector<int>v;

	//ʹ��reserveԤ���ռ�
	v.reserve(100000);

	int num = 0; //ͳ�ƿ��ٿռ�Ĵ���
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num = " << num << endl;
}


int main()
{
	test1();

	system("pause");
	return 0;
}
