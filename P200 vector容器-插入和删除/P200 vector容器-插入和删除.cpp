#include<iostream>
using namespace std;
#include<vector>

//vector�����ɾ��

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
	
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	//����
	printVector(v1);

	//βɾ
	v1.pop_back();
	printVector(v1);

	//����
	v1.insert(v1.begin(), 100); //��һ�������ǵ�����
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000); //n��elem�ķ�ʽ����
	printVector(v1);

	//ɾ��
	v1.erase(v1.begin());
	printVector(v1);

	v1.erase(v1.begin(), v1.end()); //����ķ�ʽɾ��
	printVector(v1); //�������������һ�����з�

	v1.clear(); //��ͬ��v1.erase(v1.begin(), v1.end());
	printVector(v1);
}


int main()
{
	test1();

	system("pause");
	return 0;
}