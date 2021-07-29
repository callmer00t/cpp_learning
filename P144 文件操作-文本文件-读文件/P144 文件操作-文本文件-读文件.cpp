#include<iostream>
#include<fstream> //包含头文件
#include<string>
using namespace std;

void test1()
{
	//1. 包含头文件
	//2. 创建流对象
	ifstream ifs;
	//3. 打开文件，判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4. 读数据
	//第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	//第三种
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}
	//第四种
	char c;
	while (c = ifs.get() != EOF)
	{
		cout << c;
	}
	//5. 关闭文件
	ifs.close();
}


int main()
{
	test1();

	system("pause");
	return 0;
}