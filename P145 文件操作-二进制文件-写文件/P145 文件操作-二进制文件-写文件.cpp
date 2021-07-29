#include<iostream>
#include<fstream> //包含头文件
using namespace std;

//二进制文件-写文件

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test1()
{
	//1. 包含头文件
	//2. 创建流对象
	ofstream ofs; //也可以直接写 ofstream ofs("person.txt",ios::out | ios::binary)
	//3. 打开文件
	ofs.open("person.txt", ios::out | ios::binary); //使用二进制方式写文件
	//4. 写文件
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));
	//5. 关闭文件
	ofs.close();
}

int main()
{
	test1();

	system("pause");
	return 0;
}