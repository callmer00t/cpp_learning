#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι��죬ͨ������������������
	MyArray(int capacity)
	{
		//cout << "MyArray �вι������" << endl;
		this->m_Capacity = capacity; //��ʼ����������
		this->m_Size = 0; //�����ʼΪ��
		this->pAddress = new T[this->m_Capacity]; //�����������ٶ����ռ�
	}
	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "MyArray ������������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray �����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress; //�������ṩ�Ŀ������죬�����ǳ��������
		this->pAddress = new T[arr.m_Capacity]; //������ڶ������ٿռ�
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=����
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray operator= ����" << endl;
		//���ж�ԭ�������Ƿ������ݣ�����У����ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this; //��������
	}
	//β�巨
	void Push_Back(const T& val)
	{
		//�ж������Ƿ���ڴ�С������������
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val; //val���뵽��������λ��
		this->m_Size++; //���������С
	}
	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ����
		if (this->m_Size == 0)
		{
			return;
		} //�����ǰ����Ϊ�գ�����ɾ��
		this->m_Size--; //�����С��1���߼�ɾ��
	}
	//ͨ���±�ʽ���������е�Ԫ�أ������������������
	T& operator[](int index) //������ֵ������Ϊ��ֵ���򷵻�������
	{
		return this->pAddress[index];
	}
	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int getSize()
	{
		return this->m_Size;
	}
private:
	T* pAddress; //ָ��ָ��������ٵ���ʵ����
	int m_Capacity; //��������
	int m_Size; //�����С
};