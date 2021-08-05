#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造，通过参数传入数组容量
	MyArray(int capacity)
	{
		//cout << "MyArray 有参构造调用" << endl;
		this->m_Capacity = capacity; //初始化数组容量
		this->m_Size = 0; //数组初始为空
		this->pAddress = new T[this->m_Capacity]; //按照容量开辟堆区空间
	}
	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "MyArray 析构函数调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray 拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress; //编译器提供的拷贝构造，会造成浅拷贝问题
		this->pAddress = new T[arr.m_Capacity]; //深拷贝，在堆区开辟空间
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=重载
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray operator= 调用" << endl;
		//先判断原来堆区是否有数据，如果有，先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this; //返回自身
	}
	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否等于大小（数组已满）
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val; //val插入到数组最后的位置
		this->m_Size++; //更新数组大小
	}
	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删（逻辑删除）
		if (this->m_Size == 0)
		{
			return;
		} //如果当前数组为空，无需删除
		this->m_Size--; //数组大小减1，逻辑删除
	}
	//通过下表方式访问数组中的元素（重载中括号运算符）
	T& operator[](int index) //如果令返回值可以作为左值，则返回其引用
	{
		return this->pAddress[index];
	}
	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
private:
	T* pAddress; //指针指向堆区开辟的真实数组
	int m_Capacity; //数组容量
	int m_Size; //数组大小
};