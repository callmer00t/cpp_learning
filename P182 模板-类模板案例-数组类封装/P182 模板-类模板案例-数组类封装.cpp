#include<iostream>
using namespace std;
#include<string>

//����������ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//���Զ��������������Լ��Զ����������͵����ݽ��д洢
//�������е����ݴ洢������
//���캯���п��Դ������������
//�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
//�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//����ͨ���±�ķ�ʽ���������е�Ԫ��
//���Ի�ȡ�����е�ǰԪ�ظ��������������

#include "myArray.hpp"

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test1()
{
	//MyArray <int>arr1(5);
	//MyArray<int>arr2(arr1);
	//MyArray<int>arr3(100);
	//arr3 = arr1;
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "arr1 �����Ϊ��" << endl;
	printIntArray(arr1);
	cout << "arr1 ������Ϊ��" << arr1.getCapacity() << endl;
	cout << "arr1 �Ĵ�СΪ��" << arr1.getSize() << endl;
	MyArray<int>arr2(arr1);
	cout << "arr2 �����Ϊ��" << endl;
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2 ������Ϊ��" << arr2.getCapacity() << endl;
	cout << "arr2 �Ĵ�СΪ��" << arr2.getSize() << endl;
}

//�����Զ�����������
class Person
{
public:
	Person()
	{

	};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������" << arr[i].m_Name << "\t���䣺" << arr[i].m_Age << endl;
	}
}

void test2()
{
	MyArray<Person>arr(10);
	Person p1("�����", 999);
	Person p2("����", 20);
	Person p3("槼�", 19);
	Person p4("����", 30);
	Person p5("������", 27);
	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//��ӡ����
	printPersonArray(arr);
	//�������
	cout << "arr ������Ϊ��" << arr.getCapacity() << endl;
	//�����С
	cout << "arr �Ĵ�СΪ��" << arr.getSize() << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}