#include<iostream>
using namespace std;

//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

class STUDENT
{
public:
	//属性
	string s_Name; //姓名
	int s_Id; //学号

	//行为
	void showStudent()
	{
		cout << "姓名：" << s_Name << " 学号：" << s_Id << endl;
	}

	//通过行为给函数赋值
	void setName(string name)
	{
		s_Name = name;
	}

	void setId(int id)
	{
		s_Id = id;
	}
};

int main()
{
	//实例化
	STUDENT s1;
	//对s1进行属性赋值
	s1.s_Id = 1;
	s1.s_Name = "张三";
	//显示信息
	s1.showStudent();

	STUDENT s2;
	s2.s_Id = 2;
	s2.s_Name = "李四";
	s2.showStudent();

	//通过行为赋值
	STUDENT s3;
	s3.setName("王五");
	s3.setId(3);
	s3.showStudent();

	system("pause");
	return 0;
}