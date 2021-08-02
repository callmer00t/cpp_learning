#include<iostream>
using namespace std;

//ʵ��ͨ�õĶ������������ĺ���
//������򣺴Ӵ�С
//�㷨��ѡ������
//���ԣ�char int

//��������ģ��
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//����������ģ��
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //�϶����ֵ�±�
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j]) //����϶������ֵmax����һ����j�±꣩��ֵС���򽻻�
			{
				max = j;
			}
		}
		if (max != i) //����϶������ֵ�������±�Ϊi��Ԫ�أ��򽻻�
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

//��ӡ����ģ��
template<class T>
void printArrar(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1()
{
	//����char����
	char charArr[] = "bdecfa";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArrar(charArr, num);
}

int main()
{
	test1();

	system("pause");
	return 0;
}